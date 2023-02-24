#include <stdint.h>
#include <stddef.h>
#include <limine.h>
 
// The Limine requests can be placed anywhere, but it is important that
// the compiler does not optimise them away, so, usually, they should
// be made volatile or equivalent.
 
static volatile struct limine_terminal_request terminal_request = {
    .id = LIMINE_TERMINAL_REQUEST,
    .revision = 0
};
 
static void done(void) {
    for (;;) {
        __asm__("hlt");
    }
}

typedef struct {
    char *str;
    size_t len;
} string;

static string gen_str(char *str) {
    string s;
    s.str = str;
    s.len = 0;

    while (str[s.len] != '\0') {
        s.len++;
    }

    return s;
}
 
// The following will be our kernel's entry point.
void _start(void) {
    // Ensure we got a terminal
    if (terminal_request.response == NULL
     || terminal_request.response->terminal_count < 1) {
        done();
    }
 
    // We should now be able to call the Limine terminal to print out
    // a simple "Hello World" to screen.
    struct limine_terminal *terminal = terminal_request.response->terminals[0];

    string hello = gen_str((char*)"Welcome to MidAS!");
    terminal_request.response->write(terminal, hello.str, hello.len);

    // We're done, just hang...
    done();
}
