#include<stdio.h>
#include<stdlib.h>

#define true 1

struct Students
{
    int roll;
    char name[20];
    char date[10];
    double marks[3];
};

double sum(double arr[3]){
    double s=0;
    for (int i=0; i<3; i++)
        s+=arr[i];
    
    return s; 
}

void print_array(double arr[3]){
    for (int i=0; i<3; i++)
        printf("%lf ", arr[i]);
}

void one(struct Students *std){
    for (int i=0; i<3; i++){
        double s = sum(std[i].marks);
        printf("Roll no = %d, Name = %s, Date = %s, Percentage = %lf\n", std[i].roll, std[i].name, std[i].date, s);
        // printf("%s\n", nm);
    }
}

void two(struct Students *std){
    double min=100, max=0;
    char *mx_nm, *mx_dt, *mn_nm, *mn_dt;
    int mx_r, mn_r;
    for (int i=0; i<3; i++){
        double s = sum(std[i].marks);
        s = s/3;
        if (s>max){
            max=s;
            mx_nm = std[i].name;
            mx_dt = std[i].date;
            mx_r = std[i].roll;
        }
        if (s<min){
            min=s;
            mn_nm = std[i].name;
            mn_dt = std[i].date;
            mn_r = std[i].roll;
        }
    }
    printf("Max : \nRoll no = %d Name = %s Date = %s Percentage = %lf\n", mx_r, mx_nm, mx_dt, max);
    printf("Min : \nRoll no = %d Name = %s Date = %s Percentage = %lf\n", mn_r, mn_nm, mn_dt, min);
}
//1079525376
void three(struct Students *std){
    int r;
    printf("Enter roll no : ");
    scanf("%d", &r);
    for (int i=0; i<3; i++){
        if (std[i].roll==r){
            // double *n = std[i].marks;
            printf("Roll no = %d Name = %s Date = %s Marks = ", std[i].roll, std[i].name, std[i].date);
            print_array(std[i].marks);
            printf("\n");
            return;
        }
    }
}

void four(struct Students *std){
    int n;
    printf("Enter subj no : ");
    scanf("%d", &n);
    int max=0, min=100;
    for (int i=0; i<3; i++){
        printf("%d ", std[i].marks[n]);
    }
    printf("\n");
}

int main(){
    struct Students s1, s2, s3;
    struct Students std[5];

    for (int i1=0; i1<3; i1++){
        // printf("Enter Student Details : \n");

        printf("Enter Roll No. : ");
        scanf("%d", &std[i1].roll);

        // printf("Enter Name : ");
        // scanf("%s", &std[i1].name);
        // // gets(std[i1].name);
        // // scanf("%s", &std[i1].name);
        
        // printf("Enter DOB (dd-mm-yyyy) : ");
        // // gets(std[i1].date);
        // scanf("%s", &std[i1].date);

        printf("Enter Marks : ");
        for (int i=0; i<3; i++)
            scanf("%lf", &std[i1].marks[i]);
    }

    int n;
    while (true){
        
        printf("Enter:\n1 to get Student Percentages\n2 to get min and max percetange\n3 to search student details\n4 to find max and min marks in perticular subj\n5 to end\n");
        scanf("%d", &n);

        switch(n){
        
        case 1: one(std);
                break;
        case 2: two(std);
                break;
        case 3: three(std);
                break;
        case 4: four(std);
                break;

        default:
                exit(0);
                break;
        }
    }

}