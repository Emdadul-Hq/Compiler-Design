#include<stdio.h>
#include<string.h>

char str[100];
int is_digit(char ch){
    if(ch>='0' && ch<='9') return 1;
    return 0;
}
int is_char(char ch){
    if(ch >= 'A' && ch <= 'Z') return 1;
    if(ch >= 'a' && ch <= 'z') return 1;
    return 0;
}
int is_vowel(char ch){
    if(ch == 'a'|| ch =='e' || ch == 'i' || ch == 'o' || ch =='u'||ch == 'A'|| ch =='E' || ch == 'I' || ch == 'O' || ch =='U')
        return 1;
    return 0;
}
// (A) For count no of words,letter,digit and other char
void count(){
    int cnt = 1,letter_cnt =0,digit_cnt = 0,others = 0, i,j,k,x,y;
    for(i = 0;str[i];i++){
        if(str[i]== ' ' && (is_char(str[i+1]) || is_digit(str[i+1])) )
            cnt++;
        if(is_char(str[i]))     letter_cnt++;
        if(is_digit(str[i]))    digit_cnt ++;
        if(!is_char(str[i]) && !is_digit(str[i]))   others++;
    }   
    printf("\n\n(A)\n");    
    printf("Numbers of words : %d \n",cnt);
    printf("Numbers of letters : %d \n",letter_cnt);
    printf("Numbers of digits : %d \n",digit_cnt);
    printf("Numbers of Other char : %d\n",others);
}

// (B) Seperated letters digit and other char
char letters[100],digits[100],others[100];
int inl = 0,ind =0,ino =0;
int markL[300],markD[300],markO[300];
 void seperate(){
    int i,x,y;
    for(i = 0;str[i];i++){
        x = (int)str[i];
        if(is_char(str[i]) && !markL[x]){
            letters[inl++] = str[i];
            letters[inl++] = ' ';
            markL[x] = 1;
        }
        if(is_digit(str[i]) && !markD[x]){
            digits[ind++] = str[i];
            digits[ind++] = ' ';
            markD[x] = 1;
        }
        if(!is_char(str[i]) && !is_digit(str[i]) && !markO[x]){
            others[ino++] = str[i];
            others[ino++] = ' ';
            markO[x] = 1;
        }
    }
    letters[inl] = '\0';
    digits[ind]  = '\0';
    others[ino]  = '\0';

    printf("\n\n(B)\n");
    printf("Seperated letters : %s\n",letters);
    printf("Seperated digits  : %s\n",digits);
    printf("Seperated others char : %s\n",others);
 }



// (C) Count no of vowel and consonant
void count_vowelConsonant(){
    int vowelcnt = 0,consonantcnt =0,i;
    for(i=0;str[i];i++){
        if(is_char(str[i])){
            if(is_vowel(str[i]))    vowelcnt ++;
            else    consonantcnt ++;
        }
    }
    printf("\n\n(C)\n");
    printf("Numbers of vowels : %d \n",vowelcnt);
    printf("Numbers of consonants : %d \n",consonantcnt);
}
//Find out which vowels and consonants are exised in the above string
char vw[100],cons[100];
int markV[130],markC[130],vl=0,cl =0;
void getvowelsConsonant(){
    int i,x;
        for(i=0;str[i];i++){
        x = (int)str[i];
        if(is_char(str[i])){
            if(is_vowel(str[i]) && !markV[x]){
                vw[vl++] = str[i];
                vw[vl++] = ' ';
                markV[x] = 1;
            }
            if(!is_vowel(str[i]) && !markC[x]){
                cons[cl++] = str[i];
                cons[cl++] = ' ';
                markC[x]   = 1; 
            }
        }
    }
    vw[vl] = '\0';
    cons[cl] = '\0';

    printf("\n\n(D)\n");
    printf("Vowels existed : %s\n",vw);
    printf("Consonants existed : %s\n",cons);

}

// The main Function 
int main()
{
    freopen("in.txt","r",stdin);
    scanf("%[^\n]",str);
 
    //A
    count();
    //B
    seperate();
    //C
    count_vowelConsonant();
    //D
    getvowelsConsonant();

    return 0;
}