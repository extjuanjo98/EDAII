#include <stdio.h>
#include "secuencial.h"
#include <string.h>
int leeSecuencial(char *fichero){
	FILE *f;
	int cont=0;
	tipoAlumno reg;
	if((f=fopen(fichero,"rb"))==NULL){
		fprintf(stderr,"Error: No se pudo abrir el fichero %s",fichero);
		return -1;
	}else{
		fread(&reg,sizeof(reg),1,f);
		while(!feof(f)){
		  printf("\t %d %s %s %s %s %s\n\n",cont,reg.dni,reg.nombre,reg.ape1,reg.ape2,reg.provincia);
		  cont++;
		  fread(&reg,sizeof(reg),1,f);
		}
	}
	fclose(f);
	return cont;	
}

int buscaReg(FILE *f, tipoAlumno *alumno, char *dni){
	int cont=0;
	tipoAlumno reg;
	fread(&reg,sizeof(reg),1,f);
	while(!feof(f)){
		if(!strcmp(reg.dni,dni)){
			*alumno=reg;
			return cont;
		}
		cont++;
		fread(&reg,sizeof(reg),1,f);
	}
	
	return -1;	
}

int insertaReg(char *fichEntrada, tipoAlumno *alumno){
	tipoAlumno reg;
	int cont=0;
	FILE *f;
	if((f=fopen(fichEntrada,"rb+"))==NULL){
		fprintf(stderr,"Error: No se pudo abrir el fichero %s",fichEntrada);
		return -1;
	}else{
		fread(&reg,sizeof(reg),1,f);
		while(!feof(f)){
		  cont++;
		  fread(&reg,sizeof(reg),1,f);
		}
		fwrite(alumno,sizeof(tipoAlumno),1,f);
	}
	fclose(f);
	return cont+1;	
}
