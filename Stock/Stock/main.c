#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LENGTH 50

int main()
{
    FILE *openedFiles[MAX_LENGTH];
    char filenames[MAX_LENGTH][MAX_LENGTH] = {0};
    char *id = "admin";
    char *pass = "admin";
    char checkID[MAX_LENGTH];
    char checkPass[MAX_LENGTH];
    int choose = 0;
    int choose1 = 0;
    char filename[MAX_LENGTH];
    char stockName[MAX_LENGTH];
    int quantity = 0;

    printf("----------Stock Tracking System----------\n");
    printf("*****************************************\n\n");
    flag1:
        printf("Choose the action you want to take\n");
        printf("\n 1-Login\n");
        printf(" any key --> Exit\n");
        scanf("%d",&choose);
    if(choose == 1){
        printf("ID: ");
        scanf("%s", checkID);
        printf("\nPass: ");
        scanf("%s", checkPass);

    if (strcmp(id, checkID) == 0 && strcmp(pass, checkPass) == 0) {
        printf("\nSuccessful\n");
        goto flag2;
    } else {
        printf("\nFail\n");
        goto flag1;
    }
        }else{
        printf("Logged out");
        exit(0);
        }
    flag2:
        printf("\n 1-Stock Check and Update\n");
        printf(" 2-New Addition\n");
        printf(" any key --> Exit\n");
        scanf("%d",&choose1);
        if(choose1 == 1){
        int k = 0;
        char updateStock[MAX_LENGTH];
        char newContent[MAX_LENGTH];

            for (int i = 0; i < MAX_LENGTH; i++) {
        if (filenames[i][0] != '\0' && filenames[i+1] != 'last') {
            printf("File name: %s\n", filenames[i]);
            k++;
        }
    }
        if(k == 0){
            printf("Empty\n");
        }
        if(k != 0){
        printf("Enter the name of the file you want to update: ");
        scanf("%s", updateStock);

         FILE *file = fopen(updateStock, "a+");

    if (file == NULL) {
        printf("The file could not be opened.\n");
        return 1;
    }


    char line[100];
    printf("Current content of the file:\n");
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }

        printf("New content: ");
        scanf("%s", newContent);

        fprintf(file, "%s", newContent);

        fclose(file);

        printf("\nFile updated.\n");
    }
        goto flag2;
        }else if(choose1 == 2){
    int j = 0;
    printf("Enter filename: ");
    scanf("%s", filename);

    FILE *file = fopen(filename, "w");

    if (file == NULL) {
        printf("The file could not be opened.\n");
        return 1;
    }

    printf("Stock name: ");
    scanf("%s", stockName);
    fprintf(file, "%s \n", stockName);

    printf("Stock quantity: ");
    scanf("%d", &quantity);
    fprintf(file, "%d \n", quantity);

    *openedFiles = file;

     if (j < MAX_LENGTH) {
    strcpy(filenames[j+1], "last");
    strcpy(filenames[j], stockName);
    printf("Name saved in filenames %s \n", filenames[j]);
    j++;
    printf("File name written.\n");
    } else {
    printf("Filenames array is full.\n");
    }


    fclose(file);
    printf("\nFile created and content written.\n");
    goto flag2;
        }else{

        printf("Logged out");
        exit(0);

        }


    return 0;
}
