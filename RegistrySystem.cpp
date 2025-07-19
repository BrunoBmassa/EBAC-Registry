#include <stdio.h>   // Library for user interaction
#include <stdlib.h>  // Library for memory allocation
#include <locale.h>  // Library for regional text settings
#include <string.h>  // Library for handling strings

int register_user() // Function responsible for registering users in the system
{
    // Start of variable/string declarations
    char filename[40];
    char cpf[40];
    char first_name[40];
    char last_name[40];
    char job_title[40];
    // End of variable/string declarations

    printf("Enter the CPF to be registered: "); // Collecting user's CPF
    scanf("%s", cpf); // Refers to string
    strcpy(filename, cpf); // Copies string value to filename

    // File handling
    FILE *file; // File pointer
    file = fopen(filename, "w"); // Creates a new file
    fprintf(file, cpf); // Saves the CPF to file
    fclose(file); // Closes the file

    file = fopen(filename, "a");
    fprintf(file, ",");
    fclose(file);

    printf("Enter the first name to be registered: "); // Collecting user's first name
    scanf("%s", first_name);
    file = fopen(filename, "a");
    fprintf(file, first_name);
    fclose(file);

    printf("Enter the last name to be registered: "); // Collecting user's last name
    scanf("%s", last_name);
    file = fopen(filename, "a");
    fprintf(file, last_name);
    fclose(file);

    printf("Enter the job title to be registered: "); // Collecting user's job title
    scanf("%s", job_title);
    file = fopen(filename, "a");
    fprintf(file, job_title);
    fclose(file);
}

int consult_user()
{
    char cpf[40];
    char content[200];

    printf("Enter the CPF to consult: "); // Collecting user's CPF
    scanf("%s", cpf);

    FILE *file;
    file = fopen(cpf, "r");

    if (file == NULL)
    {
        printf("Could not open the file. User not found! \n");
    }

    while (fgets(content, 200, file) != NULL)
    {
        printf("\nThese are the user's details: ");
        printf("%s", content);
        printf("\n\n");
    }

    system("pause");
}

int delete_user()
{
    char cpf[40];
    printf("Enter the CPF of the user to be deleted: "); // Getting user info
    scanf("%s", cpf);
    remove(cpf); // Deletes the file

    FILE *file;
    file = fopen(cpf, "r");

    if (file == NULL)
    {
        printf("User not found in the system! \n");
        system("pause");
    }
}

int main()
{
    int option = 0; // Defining variables
    int loop = 1;

    for (loop = 1; loop == 1;)
    {
        setlocale(LC_ALL, "Portuguese"); // Setting language (you may change if needed)

        system("cls"); // Clears the screen

        printf(" ### EBAC Registry Office ### \n\n"); // Menu start
        printf("Choose an option from the menu:\n\n");
        printf("\t1 - Register names\n");
        printf("\t2 - Consult names\n");
        printf("\t3 - Delete names\n\n");
        printf("\t4 - Exit the system\n\n");
        printf("Option: "); // Menu end

        scanf("%d,", &option); // Storing user choice

        system("cls");

        switch (option)
        {
        case 1:
            register_user(); // Function call
            break;

        case 2:
            consult_user();
            break;

        case 3:
            delete_user();
            break;

        case 4:
            printf("Thank you for using the system!\n");
            return 0;

        default:
            printf("This option is not available! \n");
            system("pause");
            break;
        }
    }
}
