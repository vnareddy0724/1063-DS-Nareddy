
Q1 AND Q2 :

when A('C') is passed

void A (char ch){
  if(('A'<= ch) && (ch <= 'H')){  ----->> true for 1st char C , true for 2nd char B , true for 3rd char A
    A(ch-1); ----->> calls A('B'), calls A('A') ,then stops for next character
    cout<<ch<<endl;
  }else{
    cout<<endl;
  }
}

then first it executes cout statement where ch = A and calls A('B') then prints B , calls A('C') prints C;

Output :A 
		B
		C	
		
when A('3') is passed:

if conditions doesnt satisfy so no recursive call prints endl.

Q3:

when B(4) is passed:

int B (int n){
  if(n==0)
    return 1;
  else{
    cout<<n<<endl;
    return n * B(n-1);
  }
}

it checks then base case it is false then jumps into else loop. first it prints n=4,then calls B(3) where it does not meet the base 
case then prints n=3 and calls B(2) prints n=2, calls B(1) prints 1 and calls B(0)  where base case get executed
returns 1
then output is :
4
3
2
1

Q4:

int C (int n){
  if(n<2)
    return 0;
  else
    cout<<n<<endl;
    return (1 + C(n/2));
}

for C(16)----> 16 < 2 -->false
				cout n --> 16
				1+C(8)
		------>8 < 2 --> false
				cout n --> 8
				1+ C(4)
		------>4 < 2 ----> false
				cout n ---> 4
				1+C(2)
		------->2< 2 ----> false
				cout n ---->2
				1+ C(1)
		-------->1 < 2 ---> true
				return 0
				
output:
16
8
4
2

Q5:

int D (int n){
  if(n<0)
    return D(-n);
    if(n<10){
      cout<<n<<endl;
      return n;
    }else{
      cout<<n<<endl;
      return D(n/10);
  }
}

for D(-2365) ---> -2365<0--->true
					D(-n)->D(2365)
			----->	2365 < 0 --> false
					2365<10 --->false
					cout n ---->2365
					D(2365/10)-> D(236)
			------>	236 < 0 -->false
					236 < 10 ---> false
					cout n ---> 236
					D(23)
			------->23 < 0 ---> false
					23 < 10 ---> false
					cout n ----> 23
					D(2)
			-------->2 < 0 --->false
					2 < 10---> true
					cout n ---->2
					return 2 ->stops
output:
2365
236
23
2					

Q6:

int NumDigits(int num){
    // Returns the "length" of an integer
    int count=0;
    
    if(num==0){
      return 0;
    }
    else{
    
      return 1+NumDigits(num/10);
    }
}

for Num(5679): ---> 5679 == 0--->false
						1+NumDigits(567)
				---> 567 == 0 --->false
						1+NumDigits(56)
				--->56 == 0 --->false
						1+NumDigits(5)
				---->5 == 0 -->false
						1+NumDigits(0)
				----> 0 == 0-->true ---> return 0;	---->1+1+1+1+NumDigits(0)--->4	

output: 4	

Q7:

int MyPow(int base, int exp){
    // Returns base^exp

if(exp==0){
  return 1;
}
else{
  
  return base*MyPow(base,exp-1);
}
}

for MyPow(2,3) --- > 2*MyPow(2,2)
				---> 2*MyPow(2,1)
				----> 2*MyPow(2,0)
				----> return 1; --->2*2*2=8
				
				
Q8:int SumArray(int A[], int n){
    // Return sum of A[0] + A[1] + … + A[n-1]
if(n<0){
  return 0;
  
}
else{
  
  return A[n]+SumArray(A,n-1);
}

}

output: for A[2,4,5,7,8,11] n=5
      A[n]+SumArray(A,n-1) --->11+A[4]
							--->11+8+A[3]
							---->11+8+7+A[2]
							----->11+8+7+5+A[1]
							----->11+8+7+5+4+A[0]
							------>11+8+7+5+4+2+[A[-1]]-->RETURN 0
							
							output:37


				
				
			


				
				
					
					

				
		
