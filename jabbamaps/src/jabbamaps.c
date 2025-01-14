#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char name[99];
    int i;
} City;

typedef struct{
    City cities[64];
    int count;
} citylist;

long long distances[64][64];
int visited[64];
long long min_cost = 100000000;
int path[64];


int city_index(citylist *cities,char *name){
    for (int i = 0; i <cities->count;i++){
        if (strcmp(cities->cities[i].name, name) == 0){
            return i;
        }
    }
    if (cities->count <64){
        strcpy(cities->cities[cities->count].name, name);
        cities->cities[cities->count].i = cities->count;
        return cities->count++;
    }
}

void lowest_cost(int city, citylist *cities, int size, long long cost, int temp_path[]){
    if (cost >= min_cost){
        return;
    }
    
    if (size == cities->count){
        min_cost = cost;
        memcpy(path,temp_path,size * sizeof(int));
        return;
    }
    
    for (int k = 0; k< cities->count; k++){
        if (!visited[k] && distances[city][k] != -1){
            visited[k] = 1;
            temp_path[size] = k;
            lowest_cost(k, cities, size + 1, cost + distances[city][k],temp_path);
            visited[k] = 0;
        }
    }
}

int main(int argc, char *argv[]){
    if (argc != 2){
        printf("Usage: ./jabbamaps <filename>");
        return 1;
    }

    FILE *pF = fopen(argv[1], "r");
    if (!pF){
        printf("File does not exist");
        return 1;
    }

    for (int i=0; i<64;i++){
        for (int j=0; j<64;j++ ){
            distances[i][j]= -1;
        }
    }

    citylist cities = {{{0}}, 0};
    char city1[99], city2[99];
    long long dist;
    char line[999];
    
    while ( fgets( line , sizeof(line) , pF )){
        if ( sscanf( line , "%[^-]-%[^:]:%lld" , city1 , city2 , &dist ) == 3){
            int idx1 = city_index(&cities, city1);
            int idx2 = city_index(&cities, city2);
            distances[idx2][idx1] = distances[idx1][idx2] = dist;
        }
    }
    
    int temp_path[64]; //initialization of the temp_path array
    temp_path[0] = 0; // sets the first variable of temp_path array to the index of the first given city (0)
    visited[0] = 1; //sets the starting city to the first given city
    lowest_cost(0,&cities,1,0,path); //calls the lowest_cost function to get the lowest cost as well as the path

    printf("We will visit the cities in the following order:\n"); 
    for (int i =0; i <cities.count;i++) {   //prints the cities in the lowest cost path
        printf("%s",cities.cities[path[i]].name); 
        printf("(->)"); 
    }
    printf("\nTotal cost: %lld", min_cost); //prints the lowest cost

    fclose(pF); //closes the file
    return 0; 
}
