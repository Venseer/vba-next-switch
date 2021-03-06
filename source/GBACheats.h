#ifndef GBA_CHEATS_H
#define GBA_CHEATS_H

struct CheatsData {
  int code;
  int size;
  int status;
  bool enabled;
  bool v3;
  uint32_t rawaddress;
  uint32_t address;
  uint32_t value;
  uint32_t oldValue;
  char codestring[20];
  char desc[128];
};

void cheatsAdd(const char *codeStr, const char *desc, uint32_t rawaddress, uint32_t address, uint32_t value, int code, int size);
void cheatsAddCheatCode(const char *code, const char *desc);
void cheatsAddGSACode(const char *code, const char *desc, bool v3);
void cheatsAddCBACode(const char *code, const char *desc);
bool cheatsImportGSACodeFile(const char *name, int game, bool v3);
void cheatsDelete(int number, bool restore);
void cheatsDeleteAll(bool restore);
void cheatsEnable(int number);
void cheatsDisable(int number);
void cheatsSaveCheatList(const char *file);
bool cheatsLoadCheatList(const char *file);
void cheatsWriteMemory(uint32_t address, uint32_t value);
void cheatsWriteHalfWord(uint32_t address, uint16_t value);
void cheatsWriteByte(uint32_t address, uint8_t value);
int cheatsCheckKeys(uint32_t keys, uint32_t extended);
void cheatListInit();
void cheatListDeinit();
void cheatsReadHumanReadable(const char *file);	
void cheatsWriteHumanReadable(const char *file);

extern int cheatsNumber;
#define CHEAT_LIST_SIZE 100
#define CHEAT_LIST_ENTRY_SIZE 100
extern CheatsData cheatsList[CHEAT_LIST_SIZE-1];
extern char* cheatsStringList[CHEAT_LIST_SIZE];

#endif // CHEATS_H
