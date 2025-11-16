#include <stdio.h>
#include <stdlib.h>   // <- nécessaire pour malloc et free
#include "functions.h"

int main(void) {
    // compter les royaumes
    int kingdoms = countSeparateKingdoms();

// lire start et target pour shortest path
    int start, target;
    if (scanf("%d %d", &start, &target) != 2) {
        return 0;
    }

    // BFS pour trouver la distance uniquement
    int dist = -1;
    if (start >= 1 && start <= N_places && target >= 1 && target <= N_places) {
        int *queue = (int*)malloc((N_places + 5) * sizeof(int));
        int *parent = (int*)malloc((N_places + 1) * sizeof(int));
        char *vis = (char*)malloc((N_places + 1) * sizeof(char));
        for (int i = 1; i <= N_places; ++i) { vis[i] = 0; parent[i] = -1; }

        int head = 0, tail = 0;
        queue[tail++] = start;
        vis[start] = 1;

        while (head < tail) {
            int u = queue[head++];
            if (u == target) break;
            for (int i = 0; i < adj_list[u].size; ++i) {
                int v = adj_list[u].neighbors[i];
                if (!vis[v]) {
                    vis[v] = 1;
                    parent[v] = u;
                    queue[tail++] = v;
                }
            }
        }

        if (vis[target]) {
            int d = 0;
            for (int cur = target; cur != start; cur = parent[cur]) d++;
            dist = d;
        }

        free(queue); free(parent); free(vis);
    }

    // Afficher les deux résultats à la fin
    printf("%d\n", kingdoms);
    printf("%d\n", dist);

    // Libérer la mémoire du graphe
    free_built_graph();

    return 0;
}
