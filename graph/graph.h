
#ifndef GRAPH_H
#define GRAPH_H

#include <stddef.h>
#include <stdbool.h>
#include <stdint.h>

/**
 * @brief Неполное определение структуры (реализуйте её самостоятельно).
 */
typedef struct graph graph_t;

/**
 * Создаёт новый пустой граф.
 * @return Указатель на граф или NULL при ошибке.
 */
graph_t *graph_init(void);

/**
 * Добавляет ребро (from, to) в граф.
 * @param g Указатель на граф.
 * @param from Номер начальной вершины.
 * @param to Номер конечной вершины.
 * @return true, если добавлено успешно, false при ошибке (например, g == NULL).
 */
bool graph_add(graph_t *g, int32_t from, int32_t to);

/**
 * Ищет ребро (from, to) в графе.
 * @param g Указатель на граф.
 * @param from Начальная вершина.
 * @param to Конечная вершина.
 * @return true, если ребро найдено, иначе false.
 */
bool graph_search(const graph_t *g, int32_t from, int32_t to);

/**
 * Освобождает всю память, связанную с графом.
 * @param g Указатель на граф или NULL.
 */
void graph_free(graph_t *g);

#endif
