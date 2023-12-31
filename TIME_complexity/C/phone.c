#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct struct_t
{
    char *name;
    char *number;
} person;

char *num_generator(void)
{
    char *num = (char *)malloc(12);
    int i;

    srand(time(NULL) + rand());

    num[0] = '0';
    num[2] = '-';

    if (rand() % 2 == 0)
        num[1] = '6';
    else
        num[1] = '7';

    for (i = 3; i < 11; i++)
        num[i] = rand() % 10 + '0';

    num[11] = '\0';

    return (num);
}

int *sort_array(person *arr)
{
    int i, flag = 1, count = 0, T_count = 0;
    person tmp;
    int *inf = malloc(sizeof(int) * 2);

while (flag == 1){
    flag = 0;
    for (i = 0; i < 99; i++)
    {
        if (strcmp(arr[i].number, arr[i + 1].number) > 0)
        {
            flag = 1;
            tmp = arr[i];
            arr[i] = arr[i + 1];
            arr[i + 1] = tmp;
        }
        T_count++;
    }
    count++;
}
    // printf("count: [%d]\n", count);
    inf[0] = count;
    inf[1] = T_count;

    return (inf);
}

int main(void)
{
    person *arr;
    int *count;
    int i, j;
    char *array_of_names[] = {
        "Alice", "Bob", "Clara", "David", "Emily",
        "Frank", "Grace", "Henry", "Irene", "Jack",
        "Kate", "Leo", "Morgan", "Natalie", "Oliver",
        "Penelope", "Quentin", "Rachel", "Samuel", "Tiffany",
        "Ulysses", "Victoria", "Walter", "Xander", "Yvonne",
        "Zachary", "Ava", "Benjamin", "Chloe", "Daniel",
        "Emma", "Frederick", "Gabriella", "Hector", "Isabella",
        "Jacob", "Katherine", "Liam", "Madison", "Noah",
        "Olivia", "Peter", "Quinn", "Ruby", "Sebastian",
        "Taylor", "Ursula", "Vincent", "Willow", "Xavier",
        "Yasmine", "Zachariah", "Abigail", "Bradley", "Cassandra",
        "Donovan", "Eleanor", "Finnegan", "Giselle", "Harrison",
        "Isla", "Jasmine", "Kieran", "Lily", "Maximus",
        "Nora", "Owen", "Penelope", "Quentin", "Rosalind",
        "Samuel", "Tabitha", "Ulysses", "Vanessa", "William",
        "Ximena", "Yvette", "Zachary", "Alexis", "Benjamin",
        "Chloe", "Declan", "Emma", "Franklin", "Grace",
        "Henry", "Isabella", "Jack", "Katherine", "Liam",
        "Madeline", "Nathaniel", "Olivia", "Peter", "Quinn",
        "Rachel", "Samuel", "Taylor", "Ulysses", "Victoria"
    };

    arr = (person *)malloc(sizeof(person) * 100);
    if (arr == NULL)
        return (1);

    // generate the array
    for (i = 0; i < 100; i++)
    {
        arr[i].name = strdup(array_of_names[i]);
        arr[i].number = num_generator();
    }

    // print the array
    // for (i = 0; i < 100; i++)
    // {
    //     printf("%s: ", arr[i].name);
    //     for (j = 0; j < 10 - strlen(arr[i].name); j++)
    //         printf(" ");
    //     printf("%s [%d]\n", arr[i].number, i);
    // }
    // printf("#################\n#################\n");
    
    count = sort_array(arr);

    // print the sorted array
    for (i = 0; i < 100; i++)
    {
        printf("%s: ", arr[i].name);
        for (j = 0; j < 10 - strlen(arr[i].name); j++)
            printf(" ");
        printf("%s\n", arr[i].number);
    }


    printf("Loops: %d\n", count[0]);
    printf("Total loops: %d\n", count[1]);

    return (0);
}