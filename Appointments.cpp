/*Program to Illustrate insertion into a linked list
  Adapted from Mullick & Sarner, Structure of Programming Languages, 1996
  pp. 93-94 
  Nested structs eliminated
  Translated into C++ (g++ target)
  Uses new instead of malloc
*/

#include <iostream>
#include <cstring>
#include <cassert>
#define NAMELENGTH 21
#define NO_OF_APPTS 4

using namespace std;

typedef struct appointment
   {char name[NAMELENGTH];
    unsigned hr;
    unsigned min;
    struct appointment *next;
   }APPT;
   
/*Prototypes for insertit and printlist functions*/
APPT* insertit(APPT *first, char person[], unsigned hrtime, unsigned mintime);
void printlist(APPT *first);
   
int main(void)
{
   APPT *head;                 // Pointer to head of linked list
   char client[21];            // Name of appointee
   unsigned apphour,           // hour of appointment
            appmin;            // minute of appointment
   int k;                      // loop counter
   char ch,                    // holder
        nl;                    // place to keep newline character
   head=NULL;
   for (k=0; k<NO_OF_APPTS; k++)
     {cout<<"Enter the name of the person for whom the appointment"<<endl;
      cout<<"is to be made...max 20 characters: ";
      cin>>client;
      cout<<"Enter the hour of the desired appointment (0..23): ";
      cin>>apphour;
      cout<<"Enter the minute of the desired appointment (0..59): ";
      cin>>appmin;
      assert((apphour>=0)&&(apphour<=23)&&(appmin>=0)&&(appmin<=59));
      head=insertit(head,client,apphour,appmin);
      printlist(head);
     }

   return 0;

}

APPT* insertit (APPT *first, char person[], unsigned hrtime, unsigned mintime)
/*Function to build and maintain linked list of appointments
  in time order
  Adapted from Mullick & Sarner, Structure of Programming Languages, 1996
  pp. 93-94
  Recoded from C
  Language: C++ (g++ target)
*/

{
  APPT *p,
       *q,
       *newp;
  bool found;
  found=false;
  q=first;
  p=first;
/*Find appropriate position for new entry*/
  while ((p!=NULL) && (!found))
    {  if ((p->hr < hrtime) || ((p->hr==hrtime) &&
                               (p->min <= mintime)))
          {q=p;                 //advance to next node
           p=p->next;
          }
       else
         found=true;
    }
/*Correct location found; create new node pointed to by newp*/    
   newp = new APPT;             
   newp->hr=hrtime;
   newp->min=mintime;
   strcpy(newp->name, person);
   
/*Insert new node into list by adjusting pointers*/
   newp->next=p;
   if (q!=p)
       q->next=newp;       //insertion not at beginning
   else
       first=newp;         //insertion is at beginning
   return (first);
}
   
void printlist (APPT *first)
/*Function to print out appointment linked list
  Adapted from Mullick & Sarner, Structure of Programming Languages, 1996
  pp. 93-94
  Converted to C++
  printing functionality removed from main to separate function
  Language: C++ (g++ target)
*/

{  APPT *p;              //auxiliary pointer to traverse list
   p=first;
   while (p!=NULL)
     {cout<<p->name<<" comes at "<<p->hr<<":"<<p->min<<endl;
      p=p->next;
     }
   return;
}