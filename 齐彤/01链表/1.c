#define LEN sizeof(struct student)

struct student{
    long num;
    float score;
    struct student *next;
};
int n;
struct student *create(void){
    struct student *head;
    struct student *p1,*p2;
    n = 0;
    p1 = p2 = (struct student *)malloc(LEN);
    scanf("%ld,%f",&p1->num, &p1->score);
    head = NULL;
    while (p1->num!=0) {
        n = n+1;
        if (n==1) {
            head = p1;
        }else {
            p2->next = p1;
        }
        p2 = p1;
        p1 = (struct student *)malloc(LEN);
        scanf("%ld,%f",&p1 -> num,&p1 -> score);
    }
    p2 -> next = NULL;
    return head;
}
void print(struct student *head){
    struct student *p;

    printf("Now,These %d records are:\n",n);
    p = head;
    if (head!=NULL) {
        do {
            printf("%ld %5.1f\n",p->num,p->score);
            p = p->next;
        } while (p!=NULL);
    }
    printf("\n",n);
}
struct student *del(struct student *head,long num){
    struct student *p1,*p2 = nullptr;
    if (head==NULL) {
        return head;
    }
    p1 = head;
    while (num!=p1->num&&p1->next!=NULL) {
        p2 = p1;
        p1 = p1 -> next;
    }
    if (num == p1 -> num) {
        if (p1 == head) {
            head = p1 -> next;
        }else{
            p2 ->next = p1 -> next;
        }
        n = n - 1;
    }else {

    }
    return head;
}
