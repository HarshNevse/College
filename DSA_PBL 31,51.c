//Journal entry management with linked lists

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
    int day;
    int month;
    int year;
}date;

typedef struct diary{
    date d;
    char content[1000];
    struct diary* next;
}diary;



diary *insert(diary *p);
void display(diary *head);
diary * search(diary *,date);
void display1(diary *);
void analysis();
int menu();


int main(){
    int op,op1,x;date d;
    diary *head=NULL, *p;
    do{
       op=menu();
       switch(op){
          case 1: head=insert(head);break;
          case 2: display(head); break;
          case 3: {
                  printf("\nEnter the date to the diary entry  : ");
                  scanf("%d%d%d",&d.day,&d.month,&d.year);
                  p=search(head,d);
                  display1(p);break;
                  }
          case 4: analysis(head);
          case 5: exit (0);
         }
    }while(op!=3);
return 0;
}

date getDate(){
    static int d=01,m=01,yr=2024;
    date p;
    p.day=d++;
    if (d==31) {d=1;m++;}
    p.month=m;
    if (m==13){m=1;yr++;}
    p.year=yr;
    return p;
}
//new entry
diary * getNode(){
    diary *p= (diary *)malloc(sizeof(diary));
	p->next=NULL;
	printf("\n--- Hey! How was  your day? ---:\n");
	              printf("--- Dear Diary, ---:");
    p->d=getDate();
    printf("\t\tTodays date is : %d/%d/%d\n", p->d.day,p->d.month,p->d.year);
    scanf("%[^.]s",p->content);
   // printf("The Data read at END getnode is %s",p->content);
	return p;
}


diary *insert(diary *head){
	diary *p= getNode();
    //printf("Your day on date %d-%d-%d was : %s ", p->d.day,p->d.month,p->d.year,p->content);
    p->next=head;
    head=p;
   // printf("\n\t\t\tEND of insert func");
    return(head);
}

void display(diary *head){
    diary *t=head;
    while(t!=NULL){
        printf("\nOn date    %d/%d/%d   %s", t->d.day,t->d.month,t->d.year, t->content);
        printf("\n---------------------------------------------------------------------------------------------\n");
        t=t->next;
    }
    printf("\n\n\n");
}

void display1(diary *t){
        printf("\n\n On date    %d/%d/%d   %s", t->d.day,t->d.month,t->d.year, t->content);
        printf("\n---------------------------------------------------------------------------------------------\n");
        printf("\n\n\n");
}


diary * search(diary *head,date d){
    diary *t=head;
    while(t!=NULL){
        if((t->d.day==d.day) && (t->d.month==d.month) && (t->d.year==d.year)){
            //printf("\nOn date    %d/%d/%d   %s", t->d.day,t->d.month,t->d.year, t->content);
            //printf("\n---------------------------------------------------------------------------------------------\n");
            return t;
        }
        t=t->next;
    }
    return NULL;
    printf("\n\n\n");

}
char ** removeStop(char t[]){
         char *tok; char impWrd[100][20];int j=0;
         int i;
         char stop[20][10]={"i","and","we","today","was","a","day","am","had","lunch","early","went","if","to","be","so","there","here","college","home"};
         tok=strtok(t," ");
         while(tok){
            for(i=0;strcmp(stop(i),tok)!=0;i++);
            if(i==20) strcpy(impWrd[j++],tok);
        }
          return impWrd;
}
void  checkPosNeg(char text[][20], int *sadCnt, int *hpyCnt, int *neuCnt){
    int i=0,j=0;
     char Positive[100][20]={"good","happy","excited","joy","yay","cheerful","contented","delighted", "ecstatic", "elated","glad","joyful","joyous","jubilant","lively","merry","peace","peaceful","calm"};
     char Negative[100][20]={"unhappy","anxiety","anxious","regretful","depressed","miserable","nervous","wretched","sucked","glum","desolate","complicated","down","gloomy","bad","sad","cry"};
             while(text[j]){
                for(i=0;strcmp(Positive[i],text[j])!=0;i++);
                if(i<18) *hpycnt++;
                for(i=0;strcmp(Negative[i],text[j])!=0;i++);
                if(i<16) *sadCnt++;
                j++;
             }
}


void analysis(diary *head){
        char text[100][20];
       int sadCnt=0, hpyCnt=0, neuCnt=0;
         diary *t=head;
         while(t!=NULL){
                  text=removeStop(t->content);
                  checkPosNeg(text,&sadCnt, &hpyCnt, &neuCnt);
                  t=t->next;
                  printf("\n\n The counts of happy and sad are %d and %d resp",hpyCnt,sadCnt);
        }

    }


int menu(){
    int op;
    printf("\n1]Make an entry\n2]Display\n3]Search entry\n4]See Analyisi\n5]Exit\n");
        printf("\nEnter your choice: ");
        fflush(stdin);
        scanf("%d",&op);
    return op;
}