// Exercise: simple program that works with a file-based database

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

// Function prototypes...
// void Database_close(struct Connection *conn);
// void die(const char *message, struct Connection *conn);
// void Address_print(struct Address *addr);
// void Database_load(struct Connection *conn);
// void Database_delete(struct Connection *conn, int id);
// void Database_write(struct Connection *conn);
// void Database_get(struct Connection *conn, int id);
// void Database_set(struct Connection *conn, int id, const char *name, const char *email);
// void Database_list(struct Connection *conn);


// Use #define to utilize the C pre-processor to define some constants
// TODO: why not use 'const int MAX_DATA = 512;' ??
#define MAX_DATA 512
#define MAX_ROWS 100

// Struct definition of an 'Address' which contains all simple(ish) data types
struct Address {
    int id;
    int set;
    char name[MAX_DATA];    // character array (i.e. string)
    char email[MAX_DATA];   // character array (i.e. string)
};

// Struct definition of a 'Database' which is just an array of Addresses
struct Database {
    struct Address rows[MAX_ROWS];
};

// Struct definition of a 'Connection' which has a pointer to a FILE and a
// pointer to a Database (struct).  This is an example of "nested structs".
struct Connection {
    FILE *file;
    struct Database *db;
};

void Database_close(struct Connection *conn) {
    // Close database "connection" by closing the FILE pointer and
    // freeing the memory allocated for the "database" (i.e. conn->db).

    if (conn) {
        if (conn->file) fclose(conn->file);
        if (conn->db) free(conn->db);
        free(conn);
    }
}

void die(const char *message, struct Connection *conn) {
    // Call this function to quit the program with the return code of (1).
    // It is common for the global variable `errno` to be set when something goes
    // wrong so we will check that variable and use `perror` to write to stderr.
    if (errno) {
        perror(message);
    } else {
        printf("ERROR: %s\n", message);
    }

    Database_close(conn);
    exit(1);
}

void Address_print(struct Address *addr) {
    // Simple print function for an Address struct
    printf("%d %s %s\n",
           addr->id, addr->name, addr->email);
}

void Database_load(struct Connection *conn) {

    int rc = fread(conn->db, sizeof(struct Database), 1, conn->file);
    if (rc != 1) die("Failed to load database.", conn);
}

struct Connection *Database_connect(const char *filename, char mode) {
    // Function that creates and returns a pointer to a `Connection` structure

    // Create a block of memory for the 'Connection' struct on the heap.
    struct Connection *conn = malloc(sizeof(struct Connection));

    // If malloc returned NULL, exit out
    if (!conn) die("Memory error", conn);

    // Create another block of memory on the heap, for the 'Database' struct,
    // and  set the pointer `conn->db` to it.
    conn->db = malloc(sizeof(struct Database));

    // If malloc returned NULL, exit out
    if (!conn->db) die("Memory error", conn);

    if (mode == 'c') {
        // Open file as "writable" (create and clear)
        conn->file = fopen(filename, "w");
    } else {
        // Open file as "readable" (read only)
        conn->file = fopen(filename, "r");

        if (conn->file) {
            Database_load(conn);
        }
    }

    if (!conn->file) die("Failed to open the file", conn);

    return conn;
}

void Database_write(struct Connection *conn) {
    rewind(conn->file);

    int rc = fwrite(conn->db, sizeof(struct Database), 1, conn->file);
    if (rc != 1) die("Failed to write database.", conn);

    rc = fflush(conn->file);
    if (rc == -1) die("Cannot flush database.", conn);
}

void Database_create(struct Connection *conn) {
    int i = 0;

    for (i = 0; i < MAX_ROWS; i++) {
        // make a prototype to initialize it
        struct Address addr = {.id = i, .set = 0};
        // then just assign it
        conn->db->rows[i] = addr;
    }
}

void Database_set(struct Connection *conn, int id, const char *name, const char *email) {
    struct Address *addr = &conn->db->rows[id];
    if (addr->set) die("Already set, delete it first", conn);

    addr->set = 1;
    // WARNING: bug, read the "How To Break It" and fix this
    char *res = strncpy(addr->name, name, MAX_DATA);
    // demonstrate the strncpy bug
    if (!res) die("Name copy failed", conn);

    res = strncpy(addr->email, email, MAX_DATA);
    if (!res) die("Email copy failed", conn);
}

void Database_get(struct Connection *conn, int id) {
    struct Address *addr = &conn->db->rows[id];

    if (addr->set) {
        Address_print(addr);
    } else {
        die("ID is not set", conn);
    }
}

void Database_delete(struct Connection *conn, int id) {
    struct Address addr = {.id = id, .set = 0};
    conn->db->rows[id] = addr;
}

void Database_list(struct Connection *conn) {
    int i = 0;
    struct Database *db = conn->db;

    for (i = 0; i < MAX_ROWS; i++) {
        struct Address *cur = &db->rows[i];

        if (cur->set) {
            Address_print(cur);
        }
    }
}

int main(int argc, char *argv[]) {

    // Define the first two, required, command line args;
    char *filename;         // argv[1]
    char action;            // argv[2]

    // Define 'Connection' struct
    struct Connection *conn;

    if (argc < 3) {
        // die("USAGE: ex17 <dbfile> <action> [action params]");
        filename = "./database";
        char action = 'l';  // default to list

        // Create `Connection` struct
        conn = Database_connect(filename, 'c');
    } else {
        filename = argv[1];
        char action = argv[2][0];

        // Create `Connection` struct
        conn = Database_connect(filename, action);
    }

    // Default ID, we will use 0
    int id = 0;

    // All actions happen to require an id as their first argument
    // so we can safely assume the 3rd CLI argument is the id, if it exists.
    // The `atoi(...)` function casts the arg to an integer.
    if (argc > 3) id = atoi(argv[3]);

    // Simple validation to ensure that the id provided (integer) is not
    // greater-than or equal-to the MAX_ROWS allowed.
    if (id >= MAX_ROWS) die("There's not that many records.", conn);

    // Dispatch control based on `action` provided
    switch (action) {

        // Create the database
        case 'c':
            Database_create(conn);
            Database_write(conn);
            break;

        // Get an item in the database given an 'id'
        case 'g':
            if (argc != 4) die("Need an id to get", conn);
            Database_get(conn, id);
            break;

        // Put an item into the database
        case 'p':
            if (argc != 6) die("Need id, name, email to set", conn);
            Database_set(conn, id, argv[4], argv[5]);
            Database_write(conn);
            break;

        // Delete an entry in the database given an 'id'
        case 'd':
            if (argc != 4) die("Need id to delete", conn);
            Database_delete(conn, id);
            Database_write(conn);
            break;

        // List entries in the database
        case 'l':
            Database_list(conn);
            break;

        // DEFAULT
        default:
            die("Invalid action, only: c=create, g=get, s=set, d=del, l=list", conn);
    }

    // Close the "connection" (hah) to the database
    Database_close(conn);

    return 0;
}
