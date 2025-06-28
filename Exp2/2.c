#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX_LENGTH 50

const char* keywords[]={"if","char","break","do","else","float","for","continue","int","long","return","static","sizeof","switch","void","while"};
int no_keywords=sizeof(keywords)/sizeof(keywords[0]);

FILE *identifierFile;
FILE *keywordFile;
FILE *operatorFile;
FILE *separatorFile;
FILE *numberFile;

int isKeyword(char *sample){
    for(int i=0;i<no_keywords;i++){
        if(strcmp(keywords[i],sample)==0){
            return 1;
        }
    }
    return 0;
}
int isOperator(char ch){
    char operators[]="+-*/<>=";
    for(int i=0;i<strlen(operators);i++){
        if(ch==operators[i]){
            return 1;
        }
    }
    return 0;
}
int isSeparator(char ch){
    char sep[]="(){};";
    for(int i=0;i<strlen(sep);i++){
        if(ch==sep[i]){
            return 1;
        }
    }
    return 0;
}


void lexical_Analyzer(const char *input){
    identifierFile=fopen("identifierFile.txt","w");
    keywordFile=fopen("keywordFile.txt","w");
    operatorFile=fopen("operatorFile.txt","w");
    separatorFile=fopen("separatorFile.txt","w");
    numberFile=fopen("numberFile.txt","w");

    char token[MAX_LENGTH];
    int i=0,j=0;
    while(input[i]!='\0'){
        if(isspace(input[i])){
            i++;
            continue;
        }

        if(input[i]=='/'&&input[i+1]=='/'){
            while(input[i]!='\n'&&input[i+1]!='\0'){
                i++;
            }
            i++;
            continue;
        }

        if(input[i]=='/'&&input[i+1]=='*'){
            i+=2;
            while(input[i]!='*'&&input[i+1]!='/'){
                if(input[i]=='\0'){
                    break;
                }
                i++;
            }
            i+=2;
            continue;
        }

        if(isalpha(input[i])||input[i]=='_'){
            j=0;
            while(isalnum(input[i])||input[i]=='_'){
                token[j]=input[i];
                i++;
                j++;
            }
            token[j]='\0';
            if(isKeyword(token)){
                fprintf(keywordFile,"%s\n",token); 
            }else{
                fprintf(identifierFile,"%s\n",token);
            }
            continue;
        }

        if(isdigit(input[i])){
            j=0;
            while(isdigit(input[i])){
                token[j++]=input[i++];
            }
            token[j]='\0';
            fprintf(numberFile,"%s\n",token);
            continue;
        } 
        
        if(isOperator(input[i])){
            fprintf(operatorFile,"%c\n",input[i]);
            i++;
            continue;
        }

        if(isSeparator(input[i])){
            fprintf(separatorFile,"%c\n",input[i]);
            i++;
            continue;
        }
        i++;
    }
    
        fclose(identifierFile);
        fclose(keywordFile);
        fclose(operatorFile);
        fclose(separatorFile);
        fclose(numberFile);
}
int main(){
    const char *input=
       "/* Multi-line comment */ \n"
        "int main() { \n"
        "   // Single line comment\n"
        "   int x = 10; \n"
        "   int y = 5; \n"
        "   int sum = x+y; \n"
        "   if(x>5) { \n"
        "   continue; \n"
        "   } float y = 3.14; \n"
        "   return 0; \n"
        "}";
    lexical_Analyzer(input);
}