#include<stdio.h>

struct rectangle
{
    int length;
    int breadth;
};

int main()
{
    struct rectangle r={10,5};
    struct rectangle *p = &r;
    
    /*
    //To create a pointer reference for heap memory:

    struct rectangle *p;
    p = (struct rectangle *)malloc(sizeof(struct rectangle))

    //for c++ : p = new rectangle;
    //Dynamic object created above.
    */

    printf("Using struct variable: %d %d\n",r.length,r.breadth);
    printf("Using pointer: %d %d\n",(*p).length,(*p).breadth);
    printf("Using pointer: %d %d\n",p->length,p->breadth);

}
