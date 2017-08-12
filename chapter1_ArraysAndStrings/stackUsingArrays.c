#include <stdio.h>

int array[100];
int stk1StartP = NULL;
int stk1EndP = NULL;
int stk2StartP = NULL;
int stk2EndP = NULL;
int stk3StartP = NULL;
int stk3EndP = NULL;
//typedef responseCode int;

int pushStack1(int c)
{
    int i;
    if(stk1StartP == NULL)
    {
        stk1StartP = 1;
        stk1EndP = 1;
        array[stk1StartP]= c;
        return 0;
    }
    else
    {
       if(stk2StartP != NULL && stk2EndP<99)
       {
           if(stk3StartP!=NULL)
           {
           if( stk3EndP<99)
           {
                
                for(i=stk3EndP;i>=stk3StartP;i--)
                {
			array[i+1]= array[i];
  
		}
                stk3EndP++;
                stk3StartP++;
           }
           else
               return -1;
           }
           for(i=stk2EndP; i>= stk2StartP;i--)
           {
               array[i+1] = array[i];
           }
           stk2EndP++;
           stk2StartP++;
       }
       else
          return -1;
    }
 
    array[++stk1EndP] = c;
    return 0;
}

int pushStack2(int c)
{
    int i;
    if(stk1StartP == NULL && stk2StartP== NULL)
    {
	stk2StartP = 2;
	stk2EndP = 2;
	array[stk2StartP] = c;
	return 0;
    }
    if(stk1StartP != NULL && stk2StartP ==NULL)
    {
    	if(stk1EndP<99)
		stk2StartP = stk2EndP = stk1EndP+1;
    	else
    	{
    	return -1;
    	}
	array[stk2StartP] = c;
	return 0;
    }
    if(stk3StartP==NULL)
    {
        if(stk2EndP <99)
           array[++stk2EndP] = c;
    }
    else
    {
        if(stk3EndP <99)
        {
           for(i=stk3EndP; i>=stk3StartP;i--)
           {
              array[i+1] = array[i];
           }
           stk3EndP++;
           stk3StartP++;
           stk2EndP = stk3StartP - 1;
           if(stk2StartP==NULL)
           {
              stk2StartP = stk2EndP;
           }
           array[stk2EndP] = c;
           return 0;
         }
         else 
             return -1;
    }
}

int pushStack3(int c)
{
  if(stk1StartP == NULL && stk2StartP==NULL && stk3StartP == NULL)
  {
    stk3StartP = 3;
    stk3EndP = 3;
  }
  else if(stk1StartP != NULL && stk2StartP == NULL && stk3StartP == NULL)
  {
  stk3StartP = stk1StartP+2;
  stk3EndP = stk1StartP+2;
  }
  else if(stk2StartP != NULL)
  {
  if(stk3StartP==NULL)
  {
    if(stk2EndP<99)
    {
      stk3StartP = stk3EndP = stk2EndP+1;
    }
    else
      return -1;
  }
  else
  {
    if(stk3EndP<100)
    {
      stk3EndP++;
      array[stk3EndP] = c;
      return 0;
    }
    else
      return -1;
  }
  }
}

int popStack1()
{
if(stk1StartP == NULL)
    return -1;
else
{
   if(stk1StartP == stk1EndP)
   {
       stk1StartP = NULL;
       return array[stk1EndP];
   }
   else
   {
      return array[stk1EndP--];
   }
}

}


int popStack2()
{
if(stk2StartP == NULL)
    return -1;
else
{
   if(stk2StartP == stk2EndP)
   {
       stk2StartP = NULL;
       return array[stk2EndP];
   }
   else
   {
      return array[stk2EndP--];
   }
}

}


int popStack3()
{
if(stk3StartP == NULL)
    return -1;
else
{
   if(stk3StartP == stk3EndP)
   {
       stk3StartP = NULL;
       return array[stk3EndP];
   }
   else
   {
      return array[stk3EndP--];
   }
}

}

void main()
{
int temp;
for(int i=0;i<256;)
{
pushStack1(i++);
pushStack1(i++);
pushStack2(i++);
pushStack3(i++);
}
temp = popStack1();
while((temp=popStack1())!=-1)
{
    printf("stack 1 = %d\n",temp);
}

while((temp = popStack2())!=-1)
{
    printf("stack 2 = %d\n", temp);
}

while((temp = popStack3())!=-1)
{
    printf("stack 3 = %d\n",temp);
}
}




