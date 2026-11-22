#include <stdio.h>
#include <string.h>

void addPhoneNumbers(int index, char myPhoneNumbers[][256]);
void showPhoneNumbers(int nextIndex, char myPhoneNumbers[][256]);
int showMenu(void);
void start(int nextIndex, char phoneNumbers[][256]);


int main(void) {
    char phoneNumbers[40][256] = {
        "+492737343800",
        "+492737387942",
        "+492789834342",
        "+492737343982"
    };
    int nextIndex = 4;
    
    
    start(nextIndex, phoneNumbers);

   return 0;
}

void start(int nextIndex,char phoneNumbers[][256]) {
   
    if (showMenu() == 0){
        // Code zum Telefonnumern anzeigen 
       showPhoneNumbers(nextIndex, phoneNumbers); 
        
    }else {
        addPhoneNumbers(nextIndex, phoneNumbers);
    } 

}

void addPhoneNumbers(int nextIndex, 
    char phoneNumbers [4][256]) {
    
    printf("Neue Nummer eingeben: ");
    char newNumber[255];
    scanf("%s", newNumber);
    strcpy(phoneNumbers[nextIndex], newNumber);
    nextIndex++;
    start(nextIndex, phoneNumbers);


}

void showPhoneNumbers (int nextIndex, char phoneNumbers [4][256]) {
    printf("Telefonnummern: \n");
    for (int i = 0; i < nextIndex; i++) {
        printf("(%d) %s \n",i , phoneNumbers[i]);
    }
    start(nextIndex, phoneNumbers);
    
}

int showMenu(void) {
    int selection;
    printf("#### Herzlich Willkommen! #### \n");
    printf("(0) Telefonnummern anzeigen \n");
    printf("(1) Neue Nummer hinzufuegen \n");
    scanf(" %d", &selection);
    printf("\n \n");
    if (selection == 0 || selection == 1) {
        return selection;
    }else {
        printf("Eingabe ungueltig. \n");
        return showMenu();
    }
}