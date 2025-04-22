//Project ISP Management System
//ByteWave Technologies
//main

//admin approval for user to sign up

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define admin_id "2513127642"
#define admin_pass "CSE115"
#define MAX_USERS 100

typedef struct
{
	char  id[50];
	char  password[15];
	char  userPlan[15];   //didnt work to plan char ip[16];char mac[20]; //for mac address assigning in users
	int   account_status; //1: active, 0: inactive
	int   connection_status; // 1= connected. 0= disconnected
	float due_bill;
} User;

//defining plans
struct Plan 
{
	char name[100];
	float price;
};


struct Plan plans[] = 
{
	{"Iron", 525}, {"Bronze", 680}, {"Silver", 890}, {"Gold", 1050}, {"Platinum", 1575}, {"Diamond", 2100}
};

//function prototypes
void loadingPage();       //done
void signUp();            //done
void login();             //done
void adminPanel();        //done
void userPanel();        //done
void showActiveUsers();   //done
void addUser();          //done
void deleteUser();       //done
void createPlanFile(); //donee
void Plans();             //done
void editPlans();         //done
void viewPlans();       //done
void exitProgram();     //done
void adminExit();      //done
void manageUser(); ///doneeee


int main()
{
    loadingPage();
	return 0;
}

void loadingPage()
{
	int choice;
	while(1)
	{
	printf("--------------------------------------------------------------\n");
	printf("              --------\033[32mWelcome to ByteWave\033[0m--------             \n");
	printf("                         Login/Sign-up                        \n");
	printf("                                                              \n");
	printf("  1.Login                                                     \n");
	printf("  2.Sign-Up                                                   \n");
	printf("  3.View Plans                                                \n");
	printf("  4.Exit                                                      \n");
	printf("                         Enter Choice                         \n");
	printf("                                                              \n");
	printf("                                                              \n");
	printf("                                                              \n");
	printf("--------------------------------------------------------------\n");
	scanf("%d", &choice);
	getchar();
	
	switch(choice)
	{
		case 1:
			login();
			break;
		
		case 2:
			signUp();
			break;
		
		case 3:
			viewPlans();
			break;
		
		case 4:
			exitProgram();
			break;
		default:
	printf("--------------------------------------------------------------\n");
	printf("              --------\033[32mWelcome to ByteWave\033[0m--------             \n");
	printf("                         Login/Sign-up                        \n");
	printf("                                                              \n");
	printf("                     Invalid Choice. Retry....                \n");
	printf("                                                              \n");
	printf("                                                              \n");
	printf("--------------------------------------------------------------\n");

	}//switchend
    }//while end
}

void login()
{
    char id[50], password[15];
	printf("--------------------------------------------------------------\n");
	printf("              --------\033[32mWelcome to ByteWave\033[0m--------             \n");
	printf("                            Login                            \n");
	printf("                                                             \n");
	printf("                   ID:");
	scanf("%s", id);
	printf("\n                                                             \n");
	printf("                   (Password limit 5-10 characters)            \n");
	printf("                   Pass:");
	scanf("%s", password);
	printf("  \n                                                          \n");
	printf("--------------------------------------------------------------\n\n");
    
    if(strcmp(id, admin_id) == 0 && strcmp(password, admin_pass) == 0)//strcmp is string comparing character by character in str 0 == true
    {
    	adminPanel();
    	return;
	}
	
	
	//r = read, w = write, 
	FILE *fp = fopen("users.txt", "r"); //file name users.txt at the file location of this project
	if(fp == NULL)// NULL represents a 0 value as its a pointer
	{
		printf("Error: Could not open file.\n");
		return;
	}
	
	User user;
	int found = 0;
	
	//reading each user credentials from file and comparing id's and passes for different users 
	while(fscanf(fp, "%s %s %s %d %d %f\n", user.id, user.password, user.userPlan, &user.account_status, &user.connection_status, &user.due_bill) != EOF) //fscanf is used for taking input from file // EOF= End of File statement then the output is shown
    {
		if(strcmp(id, user.id) == 0 && strcmp(password, user.password) == 0)
		{
			found = 1;
			fclose(fp);
			userPanel();
			return;
		}
	}
	fclose(fp);
	
	//if no match found-
	if(!found)
	{
		printf("--------------------------------------------------------------\n");
	    printf("              --------\033[32mWelcome to ByteWave\033[0m--------             \n");
	    printf("                             Login                            \n");
	    printf("                                                              \n");
	    printf("                   ID:                                        \n");
	    printf("                                                              \n");
	    printf("                  (Password limit 5-10 characters)            \n");
	    printf("                  \033[31mError!\033[0m Wrong Credentials Retry              \n");
	    printf("                                                              \n");
	    printf("--------------------------------------------------------------\n");
	}
	
}

void signUp()
{
	User user;   // no more newUser everything changed to user now                                                       
	            -//newUser and user in loginPanel might conflict, might have to change it later
	printf("--------------------------------------------------------------\n");
	printf("              --------\033[32mWelcome to ByteWave\033[0m--------             \n");
	printf("                            Sign-up                           \n");
	printf("                                                              \n");
	printf("                   ID:");
	scanf("%s", user.id);
	getchar();
	printf("                                                              \n");
	printf("                  (Password limit 5-10 characters)            \n");
	printf("                   Pass:");
	scanf("%s", user.password);
	printf("                                                              \n");
	printf("--------------------------------------------------------------\n");
    printf("                            Select Plan:                      \n");
    for(int i = 0; i < 6; i++)
    {
    printf("    %d. %s - Tk.%.2f\n", i + 1, plans[i].name, plans[i].price);
	}
	printf("--------------------------------------------------------------\n");
	//plan selection
	int planChoice;
	printf("                Enter Plan Number(1-6):                       \n");
	scanf("%d", &planChoice);
	printf("--------------------------------------------------------------\n");
	if(planChoice < 1 || planChoice > 6)
	{
	printf("--------------------------------------------------------------\n");
	printf("              --------\033[32mWelcome to ByteWave\033[0m--------             \n");
	printf("                            Sign-up                           \n");
	printf("                                                              \n");
	printf("\n");
	printf("                      \033[31mInvalid Plan Selection!\033[0m Try Again.  \n");
	printf("--------------------------------------------------------------\n");
    printf("                            Select Plan:                      \n");

	return;
	}
	//assigning selected plan
	strcpy(user.userPlan, plans[planChoice - 1].name);
	user.due_bill = plans[planChoice - 1].price;         //ALL DONE                  //need to at price of plan)done
	
	user.account_status = 1;
	user.connection_status = 1;
	
	////r = read, w = write, 
	FILE *fp = fopen("users.txt", "a");
	if(fp == NULL)
	{

	    printf("--------------------------------------------------------------\n");
	    printf("             --------\033[32mWelcome to ByteWave\033[0m--------             \n");
	    printf("                          Sign-up                            \n");
	    printf("                                                             \n");
	    printf("                  ID:                                        \n");
	    printf("                  Pass:                                      \n");
	    printf("                                                             \n");
	    printf("                     \033[31mError:\033[0m Unable to save user data!    \n");
		printf("                                                             \n");
	    printf("                                                             \n");
	    printf("                                                             \n");
	    printf("--------------------------------------------------------------\n");
		return;	
	}

	fprintf(fp, "%s %s %s %d %d %f", user.id, user.password, user.userPlan, user.account_status, user.connection_status, user.due_bill);
	fclose(fp);
	    printf("--------------------------------------------------------------\n");
	    printf("             --------\033[32mWelcome to ByteWave\033[0m--------             \n");
	    printf("                          Sign-up                            \n");
	    printf("                                                             \n");
	    printf("                  ID:                                        \n");
	    printf("                  Pass:                                      \n");
	    printf("                                                             \n");
	    printf("                    Sign-up \033[32mSuccessful!\033[0m                      \n");
		printf("                                                             \n");
	    printf("                                                             \n");
	    printf("                                                             \n");
	    printf("--------------------------------------------------------------\n");
    
}



void adminPanel()
{
	int choice;
	printf("--------------------------------------------------------------\n");
	printf("             --------\033[32mWelcome to ByteWave\033[0m--------             \n");
	printf("                          Admin Panel                        \n");
	printf("                                                             \n");
	printf("                          1. Add User                        \n");
	printf("                          2. Manage Users                    \n");
	printf("                          3. Manage Plans                    \n");
	printf("                          4. Exit                            \n");
	printf("                                                             \n");
	printf("                                                             \n");
	printf("                                                             \n");
	printf("--------------------------------------------------------------\n");
	scanf("%d", &choice);
	switch(choice)
	{
		case 1:
			signUp();
			break;
		
		case 2:
			manageUser();
			break;
		
		case 3:
		    Plans();
		    break;
		    
		case 4:
			adminExit();
			break;
			
			
			default:
	printf("--------------------------------------------------------------\n");
	printf("             --------\033[32mWelcome to ByteWave\033[0m--------             \n");
	printf("                          Admin Panel                        \n");
	printf("                                                             \n");
	printf("                 \033[31mError!\033[0m Choose a valid option(1-4)           \n");
	printf("                                                             \n");
	printf("                                                             \n");
	printf("--------------------------------------------------------------\n");
	
	adminPanel();		
	}
	
}

void showActiveUsers()
{
////r = read, w = write, 
	FILE *fp = fopen("users.txt", "r");
	User user;
	
	while (fscanf(fp, "%s %s %s %d %d %f\n", user.id, user.password, user.userPlan, &user.account_status, &user.connection_status, &user.due_bill) != EOF) 
	{
        if (user.account_status == 1)
        {
        		FILE *fp = fopen("plan.txt", "r");
        		if(fp == NULL)
        		{
         printf("--------------------------------------------------------------\n");
	    printf("                                                             \n");
	    printf("                      User Information                       \n");
	    printf("                                                             \n");
	    printf(" User ID: %s                                                 \n");
	    printf("                                                             \n");
	    printf(" Account Status: %s        Connection Status: %s             \n");
	    printf("                                                             \n"); 
	    printf("                  Error Loading Information                  \n");
	    printf(" Current Due Bill: %.2f       Plan: %s                       \n");
	    printf("                                                             \n");
	    printf("--------------------------------------------------------------\n");
			fclose(fp);
			return;
				}
				
        char planName[20];
            int bandwidth, price;
            int found = 0;

            while (fscanf(fp, "%s %d %d", planName, &bandwidth, &price) != EOF) 
			{
                if (strcmp(planName, user.userPlan) == 0) 
				{
                    found = 1;
                    break;
                }
            }

            fclose(fp);//plan.txt

            printf("--------------------------------------------------------------\n");
            printf("                                                             \n");
            printf("                         User Panel                          \n");
            printf("                                                             \n");
            printf(" User ID: %s                                                 \n", user.id);
            printf("                                                             \n");
            printf(" Account Status: %s        Connection Status: %s             \n", user.account_status ? "Active" : "Inactive", user.connection_status ? "Connected" : "Disconnected");
            printf("                                                             \n"); // didnt work :(printf(" MAC Address: %s            IP Address: %s                   \n", user.mac, user.ip);
            printf("                                                             \n");
            
            if (found) {
                printf(" Plan: %s (%dMbps)       Monthly Price: Tk.%d            \n", planName, bandwidth, price);
            } 
			else
			{
                printf(" Plan: %s                Price: Info Not Found           \n", planName);
            }

            printf(" Current Due: Tk.%.2f                                       \n", user.due_bill);
            printf("                                                             \n");
            printf("--------------------------------------------------------------\n");
        }
    }

    fclose(fp);
}
void deleteUser()
{
	User user[MAX_USERS];
	int userCount = 0;
	
	FILE *fp;
	fp = fopen("users.txt", "r");
	if(fp == NULL)
	{
		printf("\n--------------------------------------------------------------\n");
		printf("\033[31mError!\033[0m opening file!\n");
		printf("--------------------------------------------------------------\n");
		return;
	}
	
	while(fscanf(fp, "%s %s %s %d %d %.2f", user[userCount].id, user[userCount].password, user[userCount].userPlan, &user[userCount].account_status, &user[userCount].connection_status, &user[userCount].due_bill) != EOF) 
	{
		userCount++;
	}
	fclose(fp);
	
	//search user id to delete
	char confirm;
	char searchID[50];
	printf("--------------------------------------------------------------\n");
	printf("Enter the ID of the user to delete: \n");
	scanf("%s", searchID);
	
	int found = 0;
	for(int i = 0; i < userCount; i++)
	{
		if(strcmp(user[i].id, searchID) == 0) //0 in strcmp is true
		{
			for(int j = i; j < userCount - 1; j++)
			{
				user[j] = user[j + 1];
			}
			userCount--;
			found = 1;
			break;
		}
	}
	
	if(!found)
	{
		printf("--------------------------------------------------------------\n");
		printf("\nUser ID \033[31mNot\033[0m Found.\n");
		printf("--------------------------------------------------------------\n");
		return;
	}
	
	//rewriting updated list of user
	fp = fopen("users.txt", "w");
	if(fp == NULL)
	{
		printf("--------------------------------------------------------------\n");
		printf("\33[31mError\033[0m opening file!\n");
		printf("--------------------------------------------------------------\n");
		return;
	}
	
	for(int i = 0; i < userCount; i++)
	{
		fprintf(fp, "%s %s %s %d %d %f\n", user[i].id, user[i].password, user[i].userPlan, user[i].account_status, user[i].connection_status, user[i].due_bill);
	}
	
	fclose(fp);
			printf("--------------------------------------------------------------\n");
			printf("User ID '%s' removed as user successfully.\n", searchID);
    
}
void userPanel()
{
////r = read, w = write, 
	FILE *fp = fopen("users.txt", "r");
	User user;
	
	while (fscanf(fp, "%s %s %s %d %d %f\n", user.id, user.password, user.userPlan, &user.account_status, &user.connection_status, &user.due_bill) != EOF) 
	{
        if (user.account_status == 1)
        {
        		FILE *fp = fopen("plan.txt", "r");
        		if(fp == NULL)
        		{
         printf("--------------------------------------------------------------\n");
	    printf("                                                             \n");
	    printf("                      User Information                       \n");
	    printf("                                                             \n");
	    printf(" User ID: %s                                                 \n");
	    printf("                                                             \n");
	    printf(" Account Status: %s        Connection Status: %s             \n");
	    printf("                                                             \n"); 
	    printf("                  Error Loading Information                  \n");
	    printf(" Current Due Bill: %.2f       Plan: %s                       \n");
	    printf("                                                             \n");
	    printf("--------------------------------------------------------------\n");
			fclose(fp);
			return;
				}
				
        char planName[20];
            int bandwidth, price;
            int found = 0;

            while (fscanf(fp, "%s %d %d", planName, &bandwidth, &price) != EOF) 
			{
                if (strcmp(planName, user.userPlan) == 0) 
				{
                    found = 1;
                    break;
                }
            }

            fclose(fp);//plan.txt

            printf("--------------------------------------------------------------\n");
            printf("                                                             \n");
            printf("                         User Panel                          \n");
            printf("                                                             \n");
            printf(" User ID: %s                                                 \n", user.id);
            printf("                                                             \n");
            printf(" Account Status: %s        Connection Status: %s             \n", user.account_status ? "Active" : "Inactive", user.connection_status ? "Connected" : "Disconnected");
            printf("                                                             \n"); // didnt work :(printf(" MAC Address: %s            IP Address: %s                   \n", user.mac, user.ip);
            printf("                                                             \n");
            
            if (found) {
                printf(" Plan: %s (%dMbps)       Monthly Price: Tk.%d            \n", planName, bandwidth, price);
            } 
			else
			{
                printf(" Plan: %s                Price: Info Not Found           \n", planName);
            }

            printf(" Current Due: Tk.%.2f                                       \n", user.due_bill);
            printf("                                                             \n");
            printf("        --------\033[32mThank You for choosing ByteWave\033[0m--------             \n");
            printf("--------------------------------------------------------------\n");
        }
    }

    fclose(fp);
}

void createPlanFile()
{
    FILE *fp = fopen("plan.txt", "r");
    if (fp == NULL) {
        // since file doesnt exist new file is created
        fp = fopen("plan.txt", "w");
        if (fp == NULL) 
		{
            printf("Error creating plan file.\n");
            return;
        }
        // Add some initial plans to the file
        fprintf(fp, "Iron 15 525\n");
        fprintf(fp, "Bronze 25 680\n");
        fprintf(fp, "Silver 40 890\n");
        fprintf(fp, "Gold 60 1050\n");
        fprintf(fp, "Platinum 80 1575\n");
        fprintf(fp, "Diamond 100 2100\n");
        fclose(fp);
        printf("Plan file created with default plans.\n");
    } else {
        fclose(fp);
    }
} 

void Plans()
{
	int option = 0;
	
	while(option != 5)
	{
		printf("--------------------------------------------------------------\n");
	printf("             --------\033[32mWelcome to ByteWave\033[0m--------             \n");
	printf("                         Admin Panel                         \n");
	printf("\n");
	printf(" 1. Create Plans\n");
	printf(" 2. View Plans\n");
	printf(" 3. Edit Plan Prices\n");
	printf(" 4. Exit\n");
	printf("                        Enter Choice:\n");
	scanf("%d", &option);
    printf("--------------------------------------------------------------\n");
    
    
    switch(option)
    {
    	case 1:
    		createPlanFile();
    		break;
    	case 2:
    		viewPlans();
    		break;
    	
    	case 3:
    		editPlans();
    		break;
    	
    	case 4:
    		adminExit();
    		break;
    		
	}// end of switch
    }// end of while
}


void viewPlans() 
{
    FILE *fp = fopen("plan.txt", "r");
    if (fp == NULL) {
        printf("Plan file not found.\n");
        return;
    }

    char name[20];
    int speed, price;

    printf("--------------------------------------------------------------\n");
    printf("|             Plans:     |   Bandwidth:  |    Price:         |\n");
    while (fscanf(fp, "%s %d %d", name, &speed, &price) != EOF) 
	{
        printf("|  %-20s |  %-10dMbps |  Tk.%-12d |\n", name, speed, price);
    }
    printf("--------------------------------------------------------------\n");

    fclose(fp);
}

void editPlans()
{
	FILE *fp = fopen("plan.txt", "r");
	if(fp == NULL)
	{
	printf("Plan file not found.\n");
	return;
	}
	
	char name[20][20];
	int speed[10], price[10], count = 0;
	
	
	while(fscanf(fp, "%s %d %d",name[count], &speed[count], &price[count]) != EOF)
	{
		count++;
	}
	fclose(fp);
	
	//plans with indeces
	printf("Which plan do you want to edit:\n");
	for(int i = 0; i < count; i++)
	{
		printf("%d, %s - %dMbps - Tk.%d\n", i + 1, name[i], speed[i], price[i]);
	}
	
	int choice, newPrice;
	printf("Enter plan number to edit:");
	scanf("%d", &choice);
	if(choice < 1 || choice > count)
	{
		printf("\033[31mInvalid\033[0m Choice!\n");
		return;
	}
	
	printf("Enter new price for %s: ", name[choice - 1]);
	scanf("%d", &newPrice);
	
	price[choice - 1] = newPrice;
	
	fp = fopen("plan.txt", "w");
	for(int i = 0; i < count; i++)
	{
		fprintf(fp, "%s %d %d\n", name[i], speed[i], price[i]);
	}
	fclose(fp);
	
	printf("\033[32mPlan Updated Successfully\033[0m\n");
	printf("--------------------------------------------------------------\n");
}
void manageUser()
{
		int option = 0;
	
	while(option != 4)
	{
		printf("--------------------------------------------------------------\n");
	printf("             --------\033[32mWelcome to ByteWave\033[0m--------             \n");
	printf("                         Admin Panel                         \n");
	printf("\n");
	printf(" 1. View Users\n");
	printf(" 2. Add Users\n");
	printf(" 3. Delete Users\n");	
	printf(" 4. Exit\n");
	printf("                        Enter Choice:\n");
	scanf("%d", &option);
    printf("--------------------------------------------------------------\n");
    
    
    switch(option)
    {
    	case 1:
    		showActiveUsers();
    		break;
    	
    	case 2:
    		signUp();
    		break;
    	
    	case 3:
    		deleteUser();
    		break;
    	case 4:
    		adminExit();
    		break;
    		
	}// end of switch
    }// end of while
}

void exitProgram()
{
	char choice;
	printf("--------------------------------------------------------------\n\n");
	printf("Are you sure you want to exit (Y/N)?");
	scanf(" %c", &choice);
	if(choice == 'Y' || choice == 'y')
	{
		printf("--------------------------------------------------------------\n\n");
		printf("      Thank you for visiting our site. Have a great day!\n\n");
		printf("--------------------------------------------------------------\n\n");
		exit(0); //library function for exit
	}
	
	else
	{
		loadingPage();
	}
	
}

void adminExit()
{
	int choice_a;
			printf("--------------------------------------------------------------\n");
			printf(" 1. Loading page\n");
			printf(" 2. Exit Program\n");
			scanf(" %d", &choice_a);
			printf("--------------------------------------------------------------\n");
			
			switch(choice_a)
			{
			  case 1:
			  	loadingPage();
			  	break;
			
			  case 2:
			  	exit(0);
			  	break;
			  	
			default:
	printf("--------------------------------------------------------------\n");
	printf("             --------\033[32mWelcome to ByteWave\033[0m--------             \n");
	printf("                          Admin Panel                        \n");
	printf("                                                             \n");
	printf("                 \033[31mError!\033[0m Choose a valid option(1-2)           \n");
	printf("                                                             \n");
	printf("                                                             \n");
	printf("--------------------------------------------------------------\n");
	
	adminExit();
	
	}
}

/* For later!
//with the help of a senior
void macAddress(char mac[20])
{
    unsigned char mac_b[6]; // Temporary storage for MAC bytes

    for(int i = 0; i < 6; i++)
    {
        mac_b[i] = rand() % 256;
    }

    mac_b[0] |= 0x02; // locally administered bit
    mac_b[0] &= 0xFE; // Ensure unicast address

    sprintf(mac, "%02X:%02X:%02X:%02X:%02X:%02X", 
        mac_b[0], mac_b[1], mac_b[2], mac_b[3], mac_b[4], mac_b[5]);
}


void ipAddress(char ipStr[16]) 
{
    int host = rand() % 254 + 1; // Avoid 0 and 255 for host part
    sprintf(ipStr, "192.168.1.%d", host);
}
*/

