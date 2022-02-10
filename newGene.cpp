#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<conio.h>
#include<bits/stdc++.h>
using namespace std;
int main_page();
int abt_page();
int welcomepg();
int instruct();
int FAQ();
void computeLPSArray(char pat[], int M, int lps[]);
void KMPSearch(char* pat, char* txt, int M, int N);
void rundpg();
void input();
void input1();
void comparing(char D1S1[], int count1, char D2S1[], int count2);
int inputcheck(char D1S1[], char D1S2[], int count);
int welcomepg()
{
 system("cls");
 cout<<" \n \n \n \n"<<"\t\t\t\t\t\t "<<"WELCOME \n"<<"\t\t\t\t\t\t "<<"TO \n"<<"\t\t\t\t\t\t"<<"** DNA \n\t\t\t\t\t\t\n\t\t\t\t\t\t TESTING **";
 getch();
 main_page();
}
int abt_page()
{
 system("cls");
 cout<<" \n "<<"\t\t\t\t\t\t"<<"** DNA \n\t\t\t\t\t\t \n\t\t\t\t\t\t TESTING**";
 cout<<"\n ABOUT PAGE";
 cout<<"\nThis is a page where you can perform 2 tasks"<<endl;
 cout<<"The first one::To check the percent matching of 2 DNA of same or different species"<<endl;
 cout<<"The second one::To check the percentage of characteristics present in the particular DNA\n\n\n\n\n\n\n\n";
 cout<<endl<<"1.Main page"<<endl<<"2.Exit";
 cout<<"\n Choose an option to proceed: ";
 int n;
 cin>>n;
 return n;
}
int instruct()
{
 system("cls");
 cout<<" \n "<<"\t\t\t\t\t\t"<<"** DNA \n\t\t\t\t\t\t \n\t\t\t\t\t\t TESTING**";
 cout<<"\n INSTRUCTIONS PAGE\n";
 cout<<"\n INPUT:\n"<<"\n THE DNA MUST BE INPUTTED BASE BY BASE, EACH IN CAPITALS. THEY ARE STORED AS CHAHRACTER ARRAY, NOT AS STRING SO USER MUST ENTER ONE BASE AT A TIME.\n";
 cout<<"\n OUTPUT: \n"<<"\n IN THE COMPARING FUNCTION, WE COMPARE THE TWO INPUTTED DNAS AND OUTPUT THE PERCENTAGE OF DNA MATCHED."<<"\nFOR EXAMPLE IF THE OUTPUT SAYS 25% MATCH, IT MEANS THAT 25% OF DNA 1 IS PRESENT IN DNA 2. HENCE THE SPECIES 2 WILL HAVE 25% CHARACTERISTICS OF SPECIES 1.";
 cout<<"\nIN THE MATCHING CHARACTERISTICS FUNCTION, WE FIND THE % OF THE INPUT CHARACTERISTIC IN THE INPUT DNA."<<"\n FOR EXAMPLE IF WE SAY THAT THERE IS 20% MATCHING OF THE CHARACTERISTICS IN THE DNA, THEN WE CAN SAY THAT THE SPECIES HAS 20% OF THAT CHARACTERISTIC.";
 cout<<endl<<"\n\n\n\n\n\n\n\n\n1.Main page"<<endl<<"2.Exit";
 cout<<"\n Choose an option to proceed: ";
 int n;
 cin>>n;
 return n;
}
int FAQ()
{
 system("cls");
 cout<<" \n "<<"\t\t\t\t\t\t"<<"** DNA \n\t\t\t\t\t\t \n\t\t\t\t\t\t TESTING **";
 cout<<"\n FAQ PAGE\n \n";
 cout<<"Here are some general questions which arise about DNA\n\n"<<endl;
 cout<<"1. What is a &quot;strand&quot; of DNA?\n"<<endl;
 cout<<"A strand of DNA is simply a collection of deoxyribonucleotides (the monomers of a DNA molecule), sometimes called a fragment of DNA\n\n"<<endl;
 cout<<"2.How many strands make up a DNA double helix?\n"<<endl;
 cout<<"A double helix of DNA is formed when two DNA strands each having a 5&#39; and 3&#39; end wind around each other. Each of the DNA strands have nucleotides present.The two strands are held by hydrogen bonds.\n\n"<<endl;
 cout<<"3. What is the double helix?\n"<<endl;
 cout<<"It's the shape of the DNA molecule, a pair of parallel helices intertwined about a common axis.\n\n"<<endl;
 cout<<"4. Why are the two strands of the double helix described as complementary?\n"<<endl;
 cout<<"Well, because the sequence of bases on one strand determines the sequence of bases on the other strand.\n\n"<<endl;
 cout<<"5.Why are DNA strands within the double helix said to be complimentary?\n"<<endl;
 cout<<"DNA strands are said to be complementary because they both match up with each other; A with T and C with G. So if you have the strand ATGGCTA the complementary strand (the other half of the double helix) would read TACCGAT. So if you know one side of the strand then you can describe the whole.\n\n"<<endl;
 cout<<"6.One reason DNA chains twist into a double helix is for the purpose of what?\n"<<endl;
 cout<<"DNA chain twists so that the bases are closer together in the double helix. The DNA chain also takes up less space this way.\n\n"<<endl;
 cout<<"7.Each half of the DNA molecule is a DNA strand why is DNA also called a double helix?\n"<<endl;
 cout<<"Ok each half of a DNA molecule is not DNA it is RNA which is a single strand of DNA!\n\n"<<endl;
 cout<<"8.Why is RNA only synthesized from one strand of a double-stranded DNA helix?\n"<<endl;
 cout<<"Not sure but I'm going to make an educated guess, your DNA doesn't want to leave the nucleus so it stays protected, your RNA is a translator and messenger it already has the 1 strand that can cooperate with the DNA so it can copy it exactly and then translate it.\n\n"<<endl;
 cout<<endl<<"\n\n\n\n\n\n\n\n\n\ 1.Main page"<<endl<<"2.Exit";
 cout<<"\n Choose an option to proceed: ";
 int n;
 cin>>n;
 return n;
}
void KMPSearch(char* pat, char* txt, int M, int N)
{
 system("cls");
 int counter=0;
 int lps[M];
 cout<<" \n "<<"\t\t\t\t\t\t"<<"** DNA \n\t\t\t\t\t\t \n\t\t\t\t\t\t TESTING**\n\n";
 cout<<"\n\n RESULTS OF THE CHARACTERISTICS COMPARISON OF THE DNA SAMPLE";
 computeLPSArray(pat, M, lps);
 int i = 0;
 int j = 0;
 while (i < N)
 {
 if (pat[j] == txt[i])
 {
 j++;
 i++;
 }
 if (j == M)
 {
 counter++;
 j = lps[j-1];
 }
 else if (i < N && pat[j] != txt[i])
 {
 if (j != 0)
 j = lps[j-1];
 else
 i = i+1;
 }
 }
 if(counter==0)
 cout<<"\n\n THE GIVEN CHARACTERISTIC COULD NOT BE FOUND"<<endl;
 else
 {
 double per=(counter*M*100)/N;
 cout<<"\n THE DNA HAD "<<per<<"% CHARACTERISTICS"<<endl;
 }
}
void computeLPSArray(char pat[], int M, int lps[])
{
 int len = 0;
 lps[0] = 0;
 int i = 1;
 while (i < M)
 {
 if (pat[i] == pat[len])
 {
 len++;
 lps[i] = len;
 i++;
 }
 else
 {
 if (len != 0)
 {
 len = lps[len-1];
 }
 else
 {
 lps[i] = 0;
 i++;
 }
 }
 }
}
void rundpg()
{
 system("cls");
 cout<<" \n "<<"\t\t\t\t\t\t"<<"** DNA \n\t\t\t\t\t\t  \n\t\t\t\t\t\t TESTING **";
 cout<<"\n OPERATIONS OFFERED";
 int k;
 cout<<"\n 1. To compare two DNAs and know how much similar they are: ";
 cout<<"\n 2. To check how much percentage of a given characteristics is present in a DNA: ";
 cout<<"\n Choose an option to proceed: ";
 cin>>k;
 switch(k)
 {
 case 1: input1();
 break;
 case 2: input();
 break;
 default: cout<<"\n Invalid Input";
 }
}
int main_page()
{
 system("cls");
 int n;
 cout<<" \n "<<"\t\t\t\t\t\t"<<"** DNA \n\t\t\t\t\t\t \n\t\t\t\t\t\t TESTING**";
 cout<<"\n1.About Us"<<endl<<"2.Instructions"<<endl<<"3.FAQ"<<endl<<"4.Run"<<endl<<"5.Exit"<<endl;
 cout<<"Choose an option to proceed: ";
 cin>>n;
 switch(n)
 {
 case 1:
 int a1;
 a1=abt_page();
 if(a1==1)
 main_page();
 else if(a1==2)
 return 0;
 else
 cout<<"invalid input";
 break;
 case 2:
 int a2;
 a2=instruct();
 if(a2==1)
 main_page();
 else if(a2==2)
 return 0;
 else
 cout<<"invalid input";
 break;
 case 3:
 int a3;
 a3=FAQ();
 if(a3==1)
 main_page();
 else if(a3==2)
 return 0;
 else
 cout<<"invalid input";
 break;
 case 4:
 rundpg();
 break;
 case 5:
 return 0;
 default:
 cout<<"Invalid input\n" ;
 }
 return 0;
}
void input()
{
 system("cls");
 int i, m, count1=0, ch, len;
 char S1[80], S2[80], txt[35];
 cout<<" \n "<<"\t\t\t\t\t\t"<<"** DNA \n\t\t\t\t\t\t \n\t\t\t\t\t\t TESTING**";
 cout<<"\n INPUT PAGE";
 cout<<"\n Enter the number of nodes in the DNA: ";
 cin>>m;
 count1=m*10;
 cout<<"\n Enter the first strand of the DNA: \n";
 for(i=0;i<count1;i++)
 {
 cin>>S1[i];
 }
 cout<<"\n Enter the second strand of the DNA: \n";
 for(i=0;i<count1;i++)
 {
 cin>>S2[i];
 }
 ch=inputcheck(S1,S2, count1);
 if(ch==1)
 {
 cout<<"\n The first strand of the DNA : \n ";
 for(i=0;i<count1;i++)
 {
 cout<<S1[i]<<" ";
 }
 cout<<"\n The second strand of the DNA :\n ";
 for(i=0;i<count1;i++)
 {
 cout<<S2[i]<<" ";
 }
 }
 if(ch!=1)
 {
 cout<<"\n The inputed DNA were incorrect. Kindly re-input.";
 input();
 }
 else
 {
 cout<<"\n Enter the length of the characteristics to the compared with the DNA sample";
 cin>>len;
 cout<<"\n Enter the characteristics to the compared with the DNA sample";
 for(i=0;i<len;i++)
 {
 cin>>txt[i];
 }
 getch();
 KMPSearch(S1,txt, len, count1);
 }
}
void input1()
{
 system("cls");
 int i, m1, m2, count1=0, count2=0, ch1, ch2;
 char D1S1[80], D1S2[80], D2S1[80], D2S2[80];
 cout<<" \n "<<"\t\t\t\t\t\t"<<"** DNA \n\t\t\t\t\t\t  \n\t\t\t\t\t\t TESTING**";
 cout<<"\n INPUT PAGE";
 cout<<"\n Enter the number of nodes in the DNA 1: ";
 cin>>m1;
 count1=m1*10;
 cout<<"\n Enter the first strand of the DNA 1: \n";
 for(i=0;i<count1;i++)
 {
 cin>>D1S1[i];
 }
 cout<<"\n Enter the second strand of the DNA 1: \n";
 for(i=0;i<count1;i++)
 {
 cin>>D1S2[i];
 }
 ch1=inputcheck(D1S1,D1S2, count1);
 cout<<"\n Enter the number of nodes in the DNA 2: ";
 cin>>m2;
 cout<<"\n Enter the first strand of the DNA 2: \n";
 count2=m2*10;
 for(i=0;i<count2;i++)
 {
 cin>>D2S1[i];
 }
 cout<<"\n Enter the second strand of the DNA 2: \n";
 for(i=0;i<count2;i++)
 {
 cin>>D2S2[i];
 }
 ch2=inputcheck(D2S1,D2S2, count2);
 if(ch1==1)
 {
 cout<<"\n The first strand of the DNA 1 : \n ";
 for(i=0;i<count1;i++)
 {
 cout<<D1S1[i]<<" ";
 }
 cout<<"\n The second strand of the DNA 1:\n ";
 for(i=0;i<count1;i++)
 {
 cout<<D1S2[i]<<" ";
 }
 }
 if(ch2==1)
 {
 cout<<"\n The first strand of the DNA 2 : \n ";
 for(i=0;i<count2;i++)
 {
 cout<<D2S1[i]<<" ";
 }
 cout<<"\n The second strand of the DNA 2:\n ";
 for(i=0;i<count2;i++)
 {
 cout<<D2S2[i]<<" ";
 }
 }
 if(ch1!=1 || ch2!=1)
 {
 cout<<"\n The inputed DNA were incorrect. Kindly re-input.";
 input1();
 }
 getch();
 comparing(D1S1, count1, D2S1, count2);
}
void comparing(char D1S1[], int count1, char D2S1[], int count2)
{
 system("cls");
 int i, a=0,b=0, m;
 cout<<" \n "<<"\t\t\t\t\t\t"<<"** Device \n\t\t\t\t\t\t and \n\t\t\t\t\t\t Analyze **\n\n";
 cout<<"\n RESULTS OF DNA SAMPLE COMPARISON";
 if(count1!=count2)
 {cout<<"\n The two DNAs cannot be compared as the strand lengths vary.";
 }
 else
 {
 for(i=0; i<count1;i++)
 {
 if(D1S1[i]==D2S1[i])
 {
 a++;
 }
 else
 {
 b++;
 }
 }
 m=((a)/(a+b))*100;
 cout<<"\n\n \n From the comparison of the two DNA samples, it is identified that the percentage of similarity between the two DNAs are "<<m;
 }
}
int inputcheck(char D1S1[], char D1S2[], int count)
{
 int i, a=0, b=0, m=0;
 for(i=0;i<count;i++)
 {
 if(D1S1[i]=='A')
 {if(D1S2[i]=='T')
 {
 a++;
 }
 else
 { b++;
 break;
 }
 }
 else if(D1S1[i]=='T')
 {if(D1S2[i]=='A')
 {
 a++;
 }
 else
 { b++;
 break;
 }
 }
 else if(D1S1[i]=='G')
 {if(D1S2[i]=='C')
 {
 a++;
 }
 else
 { b++;
 break;
 }
 }
 else if(D1S1[i]=='C')
 {if(D1S2[i]=='G')
 {
 a++;
 }
 else
 { b++;
 break;
 }
 }
 else
 {
 m++;
 }
 }
 if(b==0 && m==0)
 {
 cout<<"\n The Inputed DNA is correct";
 return 1;
 }
 else
 {
 cout<<"\n The Inputed DNA is incorrect";
 return 0;
 }
}
int main()
{
 welcomepg();
 getch();
 system("cls");
 return 0;
}
