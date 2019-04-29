#include<iostream.h>
#include<conio.h>
int n;
class matrix
{
   private:
       float a[10][11];
       int i,j,k;
   public:
       void get_eqn();
       void printsol();
       void calculate();
       void printmat();
       void print_eqns();
       void check_similarity();
       void option();
       void correct();
       void swap();
};

void matrix::get_eqn()
{
  cout<<"Enter the number of variables\n1~10\n";
  cin>>n;
  cout<<"\nEnter the coefficients of equations in this format :\nap+bq+cr+ds+.......=n\n";
  for(i=0;  i<n;  i++)
  {
    cout<<"Enter equation number "<<i+1<<"\n";
    for(j=0;  j<n+1;  j++)
    { if(j==n)  cout<<"n=";
      else      cout<<char('a'+j)<<"=";
      cin>>a[i][j];
    }
    if(i)  check_similarity();
  }
}

void matrix::check_similarity()
{
  for(k=0;  k<i && k>=0;  k++)
  for(j=0;  j<n-1;        j++)
  {
    if(a[k][j]/a[i][j]==a[k][j+1]/a[i][j+1])
    {
      if(j==n-2)
      {
	if(a[k][j]/a[i][j]==a[k][n]/a[i][n])
	  cout<<"Algebraically equation no. "<<k+1<<" and "<<i+1<<" are one and the same.\n";
	else
	  cout<<"Solution is not possible for equation no. "<<k+1<<" and "<<i+1<<endl;
	option();
      }
    }
    else  j=n+1;
  }
}

void matrix::option()
{
  cout<<"Press\t0 to exit OR\n\tno. of the equation which is to be corrected.\n";
  cin>>k;  k--;
  if(k+1)   correct();
  else      n=0;
}

void matrix::correct()
{
  if(k<=i)
  {
    cout<<"Enter new equation no."<<k+1<<endl;
    for(j=0;  j<=n && k<n;  j++)
    {
      cout<<char('a'+j)<<"=";
      cin>>a[k][j];
    }
  }
  check_similarity();
}

void matrix::print_eqns()
{ clrscr();
  cout<<"\nThe equations are:\n";
  for(i=0;  i<n;  i++)
  {
    for(j=0;  j<=n;  j++)
    {
      if(j==n)   cout<<"="<<a[i][j];
      else
      {
	if(a[i][j]>=0 && j<n && j>0)   cout<<"+";
	cout<<a[i][j]<<char('p'+j)<<"\t";
      }
    }
    cout<<endl;
  }
}

void matrix::swap()
{
  if(a[0][0]/a[1][0]==a[0][1]/a[1][1])
  for(j=0; j<=n; j++)
  {
    a[9][j]=a[1][j];
    a[1][j]=a[2][j];
    a[2][j]=a[9][j];
  }
}

void matrix::calculate()
{
  for(i=0;i<n;i++)               //LOWER TRIANGLE
  for(j=0;j<=i;j++)
  for(k=0;k<n+1;k++)
  {
    if(i==j)
    {
      if(j==k)    k++;
      a[i][k]=a[i][k]/a[i][j];
      if(k==n)
	a[i][j]=a[i][j]/a[i][j];
    }
    else
    {
      if(j==k)   k++;
      a[i][k]=a[i][j]*a[j][k]-a[i][k];
      if(k==n)
	a[i][j]=a[i][j]*a[j][j]-a[i][j];
    }
  }
  for(i=0; i<n; i++)
  if(a[i][i]==0)
  {
    cout<<"\nMath Error.";
    n=0;
  }
  for(i=0;i<n-1;i++)                //UPPER TRIANGLE
  for(j=i+1;j<n;j++)
  for(k=0;k<n+1;k++)
  {
    if(j==k)      k++;
    a[i][k]=a[i][k]-a[i][j]*a[j][k];
    if(k==n)
    a[i][j]=a[i][j]-a[i][j]*a[j][j];
  }
}

void matrix::printsol()
{
  cout<<"\nSoution for the equations is \n";
  for(i=0;  i<n;  i++)
  {
    cout.precision(2);
    cout<<char('p'+i)<<" = "<<a[i][n]<<endl;
  }
}

void main()
{
  clrscr();
  matrix A;
  A.get_eqn();
  if(n)
  {
    A.print_eqns();
    A.swap();
    A.calculate();
    if(n!=0)
    A.printsol();
    getch();
  }
}

void matrix::printmat()
{
  cout<<"\n\n";
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n+1;j++)
      cout<<a[i][j]<<" ";
    cout<<endl;
  }
}


/* OUTPUT:

The equations are:
1p      +2q     +3r     =4
5p      +1q     +6r     =4
2p      +3q     +1r     =7

Soution for the equations is
p = 0.64
q = 1.97
r = -0.19
*/
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
