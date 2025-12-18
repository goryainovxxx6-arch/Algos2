
#include "graph.h"
#include <stdlib.h>
#include <string.h>

typedef struct {
  int32_t from;
  int32_t to;
} edge_t;
// указатель, кол-во, вместимость массива
struct graph {
  edge_t *edges;
  size_t size;
  size_t capacity;
};

#define init_capacity 4
// выделение памяти под структуру графа
graph_t *graph_init(void) {
  graph_t *g = malloc(sizeof(graph_t));
  if (!g) return NULL;
  // выделение памяти под начальный массив ребер
  g->edges = malloc(init_capacity * sizeof(edge_t));
  if (!g->edges) {
    free(g);
    return NULL;
}

g->size = 0;
g->capacity = init_capacity;

return g;
}
// расширение буфера
static bool graph_expand(graph_t *g) {
  size_t new_capacity = g->capacity * 2;
  edge_t *new_data = realloc(g->edges, new_capacity * sizeof(edge_t));
  if (!new_data) return false;

  g->edges = new_data;
  g->capacity = new_capacity;
  return true;
}
// добавление ребра
bool graph_add(graph_t *g, int32_t from, int32_t to) {
  if (!g) return false;
  // проверка на дупликат
  for (size_t i = 0; i < g->size; i++) {
    if (g->edges[i].from == from && g->edges[i].to == to)
      return true;
  }
  // расширение массива
  if (g->size == g->capacity) {
    if (!graph_expand(g)) return false;
  }
  // добавление ребра в конец массива
  g->edges[g->size].from = from;
  g->edges[g->size].to = to;
  g->size++;
  
  return true;
}
// поиск ребра в графе
bool graph_search(const graph_t *g, int32_t from, int32_t to) {
  if (!g) return false;
  // поиск по всем ребрам
  for (size_t i = 0; i < g->size; i++) {
    if (g->edges[i].from == from && g->edges[i].to == to)
      return true;
  }

  return false;
}
// освобождение памяти
void graph_free(graph_t *g) {
  if (!g) return;
  free(g->edges);
  free(g);
}
