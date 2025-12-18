
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "graph.h"

#define CHECK(cond, fmt, ...) \
    do { \
        if (!(cond)) { \
            fprintf(stderr, "\n❌ Test failed at %s:%d\n", __FILE__, __LINE__); \
            fprintf(stderr, "   → " fmt "\n", ##__VA_ARGS__); \
            exit(1); \
        } \
    } while (0)

#define INFO(fmt, ...) printf("▶ " fmt "\n", ##__VA_ARGS__)

int main(void) {
    printf("===== GRAPH (EDGE LIST) AUTOMATED TESTS =====\n\n");

    // --- Test 1: Initialization ---
    INFO("Test 1: Graph initialization");
    graph_t *g = graph_init();
    CHECK(g != NULL, "graph_init() returned NULL");

    // --- Test 2: Adding edges ---
    INFO("Test 2: Adding edges");
    CHECK(graph_add(g, 1, 2), "graph_add(1,2) failed");
    CHECK(graph_add(g, 2, 3), "graph_add(2,3) failed");
    CHECK(graph_add(g, 3, 1), "graph_add(3,1) failed");

    // --- Test 3: Searching edges ---
    INFO("Test 3: Searching existing edges");
    CHECK(graph_search(g, 1, 2), "edge (1,2) not found");
    CHECK(graph_search(g, 2, 3), "edge (2,3) not found");
    CHECK(graph_search(g, 3, 1), "edge (3,1) not found");

    INFO("Test 4: Searching nonexistent edges");
    CHECK(!graph_search(g, 1, 1), "unexpected edge (1,1) found");
    CHECK(!graph_search(g, 4, 5), "unexpected edge (4,5) found");

    // --- Test 5: Many edges ---
    INFO("Test 5: Adding many edges");
    for (int i = 0; i < 1000; i++)
        CHECK(graph_add(g, i, i + 1), "mass add failed at i=%d", i);

    for (int i = 0; i < 1000; i++)
        CHECK(graph_search(g, i, i + 1), "mass search failed for edge (%d,%d)", i, i + 1);

    // --- Test 6: Robustness ---
    INFO("Test 6: Robustness (NULL arguments)");
    CHECK(!graph_add(NULL, 1, 2), "graph_add(NULL,...) should return false");
    CHECK(!graph_search(NULL, 1, 2), "graph_search(NULL,...) should return false");
    graph_free(NULL);  // should not crash
    printf("   ✓ Robustness checks passed.\n");

    // --- Test 7: Free memory ---
    INFO("Test 7: Freeing memory");
    graph_free(g);

    printf("\n✅ All tests passed successfully!\n");
    printf("========================================\n");
    return 0;
}
