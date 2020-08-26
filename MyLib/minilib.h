/*                     MINILIB.H

 Create         03.10.02�. 14:15:35
 Last   edit    07.10.02�. 20:44:16

 Head for "minilib.c"

 */

 #define MSG_SIZE  40
 #define COUNT_ERR 9

 typedef struct err_msg
  {
    char id_err;            // Max id_err = 128  errors
    char msg_us[MSG_SIZE];  // ASCII code page standart
    char msg_ru[MSG_SIZE];  // Text russian is msg_codepage
    int msg_codepage;       // User code page
  } err_msg;

 err_msg __flash dict_err_msg[COUNT_ERR] = {\
 1,"Syntax Error:  1", "�訡�� ᨭ⠪��:  1", 866,\
 2,"Syntax Error:  2", "�訡�� ᨭ⠪��:  2", 866,\
 3,"Syntax Error:  3", "�訡�� ᨭ⠪��:  3", 866,\
 4,"Syntax Error:  4", "�訡�� ᨭ⠪��:  4", 866,\
 5,"Syntax Error:  5", "�訡�� ᨭ⠪��:  5", 866,\
 6,"Syntax Error:  6", "�訡�� ᨭ⠪��:  6", 866,\
 7,"Syntax Error:  7", "�訡�� ᨭ⠪��:  7", 866,\
 254,"Error counter parameters: 254", "�訡�� � ������⢥ ��ࠬ��஢: 254", 866,\
 255,"Function not found: 255", "�㭪樨 ��� � ᫮���: 255", 866};

 
 
 
 