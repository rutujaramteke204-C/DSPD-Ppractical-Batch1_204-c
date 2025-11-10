#include <stdio.h>

struct student
{
    char name[10];
    int year;
    char branch[10];
    float average;
};

int main()
{
    struct student s[50], temp;
    int n;

    printf("Enter number of students: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        printf("\nEnter details of student %d\n", i+1);

        printf("Enter name: ");
        scanf("%s", s[i].name);

        printf("Enter year: ");
        scanf("%d", &s[i].year);

        printf("Enter branch: ");
        scanf("%s", s[i].branch);

        printf("Enter average marks: ");
        scanf("%f", &s[i].average);
    }

    // Sorting by average (descending)
    for(int i = 0; i < n-1; i++)
    {
        for(int j = 0; j < n-i-1; j++)
        {
            if(s[j].average < s[j+1].average)
            {
                temp = s[j];
                s[j] = s[j+1];
                s[j+1] = temp;
            }
        }
    }

    printf("\nSorted Student Details (by average marks):\n");
    for(int i = 0; i < n; i++)
    {
        printf("Name: %s, Year: %d, Branch: %s, Average: %.2f\n",
               s[i].name, s[i].year, s[i].branch, s[i].average);
    }

    return 0;
}