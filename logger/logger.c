#include "logger.h"
void logMessage(char *logMsg){
  if(logger.file != NULL){
    fprintf(logger.file, "%s", logMsg);
  }else{
    startLogger("log.txt");
  }
}

void startLogger(char *path){
  logger.file = fopen(path, "w");
  logMessage("=================================================\n");
  logMessage("Inicio da execucao: Supermercado Algoritmico\n");
  logMessage("Israel Barreto Sant'Anna, Vytor dos Santos Bezerra Calixto\n");
  logMessage("=================================================\n\n");
}

void endLogger(){
  logMessage("\n=================================================\n");
  logMessage("Fim da execução\n");
  fclose(logger.file);
}
