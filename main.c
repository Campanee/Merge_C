#include <stdio.h>
#include <string.h>

int main(void) {
  //Dichiarazione
  FILE * f1;
  FILE * f2;
  FILE * f3;
  FILE * filelungo;
  //Dichiarazione di vettori
  char riga1[500], riga2[500], rigalungo[500];
  //Lettura dei due file di testo da ordinare
  f1=fopen("nomi1.txt","r");
  f2=fopen("nomi2.txt","r");
  //Creazione e scrittura
  f3=fopen("Ordine.txt","w");

  fgets (riga1, 500,f1);
  fgets (riga2, 500,f2);
  
  while(!feof(f1) && !feof(f2)){
    if(strcmp(riga1,riga2)<0){
      fprintf(f3,"%s",riga1);
      fgets(riga1, 500, f1);
    }else{
      fprintf(f3,"%s",riga2);
      fgets(riga2, 500, f2);
    }
  }
  if(feof(f1)){
    filelungo=f2;
    strcpy(rigalungo, riga2);
  }else{
    filelungo=f1;
    strcpy(rigalungo, riga1);
  }
  
  while(!feof(filelungo)){
    fprintf(f3,"%s",rigalungo);
    fgets (rigalungo,500,filelungo);
  }
  fclose (f1);
  fclose (f2);
  fclose (f3);
  printf("Il programma è stato eseguito con successo");
  return 0;
}
