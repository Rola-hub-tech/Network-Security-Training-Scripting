#include <stdio.h>
#include <stdlib.h>

struct employee{
    int ID;
    char name[100];
    float salaryPerHour;
    int workingHours;
    float totalSalary;
    float tax;
    float netSalary;
};

float calculateTotalSalary(float salaryPerHour, int workingHours){
    float totalSalary = salaryPerHour * workingHours;

    return totalSalary;
}

float calculateTax(float totalSalary){
    float tax;

    if(totalSalary >= 0.0 && totalSalary <= 14999.0){
        tax = 0.0 + ((totalSalary - 0.0) * 15 / 100);
    }

    else if(totalSalary >= 15000.0 && totalSalary <= 29999.0){
        tax = 2250.0 + ((totalSalary - 15000.0) * 16 / 100);
    }

    else if(totalSalary >= 30000.0 && totalSalary <= 49999.0){
        tax = 4650.0 + ((totalSalary - 30000.0) * 18 / 100);
    }

    else if(totalSalary >= 50000.0 && totalSalary <= 79999.0){
        tax = 8250.0 + ((totalSalary - 50000.0) * 50 / 100);
    }

    else if(totalSalary >= 80000.0 && totalSalary <= 150000.0){
        tax = 14250.0 + ((totalSalary - 80000.0) * 25 / 100);
    }

    return tax;
}

float calculateNetSalary(float totalSalary, float tax){
    float netSalary = totalSalary + ((52/100) * totalSalary) - tax;

    return netSalary;
}

int main()
{
    struct employee employeeData[10] = {0};
    int totalEmployees = 0;

    while(1){
        int operation;
        printf("Please choose an operation: \n1)Add an employee\n2)Display data of an employee\n3)Display employees data\n");
        scanf("%d", &operation);

        if(operation == 1){
            int numberOfEmployees;
            FILE *fptr = fopen("Employee Data.txt", "a");
            printf("Enter the number of employees: ");
            scanf("%d", &numberOfEmployees);
            for(int i = 0; i < numberOfEmployees; i++)
            {
                int currentIndex = totalEmployees + i;
                printf("ID: ");
                scanf("%d", &employeeData[currentIndex].ID);
                printf("Name: ");
                scanf("%s", &employeeData[currentIndex].name);
                printf("Salary per hour: ");
                scanf("%f", &employeeData[currentIndex].salaryPerHour);
                printf("Working Hours: ");
                scanf("%d", &employeeData[currentIndex].workingHours);
                employeeData[currentIndex].totalSalary = calculateTotalSalary(employeeData[currentIndex].salaryPerHour, employeeData[currentIndex].workingHours);
                employeeData[currentIndex].tax = calculateTax(employeeData[currentIndex].totalSalary);
                employeeData[currentIndex].netSalary = calculateNetSalary(employeeData[currentIndex].totalSalary, employeeData[currentIndex].tax);

                fprintf(fptr, "%d\n", employeeData[currentIndex].ID);
                fprintf(fptr, "%s\n", employeeData[currentIndex].name);
                fprintf(fptr, "%f\n", employeeData[currentIndex].salaryPerHour);
                fprintf(fptr, "%d\n", employeeData[currentIndex].workingHours);
                fprintf(fptr, "%f\n", employeeData[currentIndex].totalSalary);
                fprintf(fptr, "%f\n", employeeData[currentIndex].tax);
                fprintf(fptr, "%f\n\n", employeeData[currentIndex].netSalary);
            }
            fclose(fptr);
            totalEmployees += numberOfEmployees;
        }else if(operation == 2){
            int ID;
            printf("Enter the ID of the employee to display data: ");
            scanf("%d", &ID);
            for(int i = 0; i < totalEmployees; i++)
            {
                if(employeeData[i].ID == ID){
                    printf("ID: %d\n", employeeData[i].ID);
                    printf("Name: %s\n", employeeData[i].name);
                    printf("Salary per hour: %f\n", employeeData[i].salaryPerHour);
                    printf("Working hours: %d\n", employeeData[i].workingHours);
                    printf("Total Salary: %f\n", employeeData[i].totalSalary);
                    printf("Tax: %f\n", employeeData[i].tax);
                    printf("Net Salary: %f\n", employeeData[i].netSalary);
                    break;
                }
            }
        }else if(operation == 3){
            for (int i = 0; i < totalEmployees; i++) {
                printf("\nEmployee %d:\n", i + 1);
                printf("ID: %d\n", employeeData[i].ID);
                printf("Name: %s\n", employeeData[i].name);
                printf("Salary per hour: %f\n", employeeData[i].salaryPerHour);
                printf("Working hours: %d\n", employeeData[i].workingHours);
                printf("Total Salary: %f\n", employeeData[i].totalSalary);
                printf("Tax: %f\n", employeeData[i].tax);
                printf("Net Salary: %f\n", employeeData[i].netSalary);
            }
        }else if(operation == 0){
            break;
        }
    }

    return 0;
}
