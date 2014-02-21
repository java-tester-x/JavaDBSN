#ifndef dllDbsnH
#define dllDbsnH
//#include <iostream.h>
//#include <fstream.h>
#include <io.h>
using namespace std;

#define     REC_DELETED      1
#define     OUT_OF_RANGE     2
#define     DBN_IS_EMPTY     4
#define     REC_EMPTY        8
#define     BAD_SUBSTNUMBER  16

#define     FATAL_ERROR      256
#define     BAD_PTR          256
#define     BAD_NUMBER       512
#define     DBS_NOT_EXIST    1024
#define     DBN_NOT_EXIST    2048
#define     BUFFER_SMALL     4096
#define     BAD_TABLE_NAME   8192
#define     BAD_TABLE_HANDLE 16384
#define     DBR_NOT_EXIST    32768

#define     ALL_FRAGM 0
#define     ACTIVE_FRAGM 1
#define     ALL_BACK 2
#define     ACTIVE_BACK 3


/*
typedef  unsigned int  uint;
typedef  unsigned long  ulong;

#define hndlEmpty	 0x80000000     //- обрабатывать пустые записи
#define notEdit		 0x40000000     //- не изменять запись
#define notInsCut	 0x20000000     //- не вставлять и не вырезать элем
#define notAppend	 0x10000000     //- не добавлять
#define notModify	 0x70000000     //- не изменять список
#define notView 	 0x08000000     //- не отображать на экране

#define SpStrHead    0x74532553     //  S%St
#define SpBinHead    0x6E422553     //  S%Bn
#define SpSpHead     0x70532553     //  S%Sp
#define SpFnHead     0x6E462553     //  S%Fn


const   LOCAL_LINK     = 1;   //-- признак ссылки на внутренний подсписок
const   FILE_LINK      = 2;   //-- признак ссылки на файл
const   DIR_LINK = 3;   //-- признак ссылки на каталог
const   FILEDBS_LINK   = 4;   //-- признак ссылки на файл базы фрагментов
const   FRAGMENT_LINK  = 5;   //-- признак ссылки на фрагмент

extern "C" int    __declspec(impexp) __stdcall
	SpadSbsLen(  spad* pSpad, int  NomSubst);

extern "C" int    __declspec(impexp)  __stdcall 
	SubstCount(char* pc = 0);


*/

#ifdef DBSNEXPORT
	#define		impexp	dllexport
#else
	#define		impexp	dllimport
#endif


#include <string>
#include <stdio.h>

//---------------------------------------------------------------------------

//-- создать пустой массив целых чисел
extern "C" int    __declspec(impexp) __stdcall   getLongArray( int count );

//-- сравнить 2 строки с учетом подстрок и игнорирование регистра
extern "C" long    __declspec(impexp) __stdcall    compSpec( char* pc, char* pc1);

//-- сосчитать длину строки
extern "C" int    __declspec(impexp) __stdcall    getLen( char* pc);

//-- сосчитать число подстрок в строке
extern "C" int    __declspec(impexp) __stdcall    substCount( char* pc);

//-- вытащить подстроку с заданным номером из строки
extern "C" int    __declspec(impexp) __stdcall  getSubst(char* pc, char* pcbuf, int buf_sze, int nom_sub);

//== добавить подстроку к строке сзади
extern "C" int    __declspec(impexp) __stdcall
    addSubst(char* pc, char* pcres, int res_size, char* pcsubst);

//== вставить подстроку в нужное место строки
extern "C" int    __declspec(impexp) __stdcall
    insSubst(char* pc, char* pcres, int res_size, int nom_sub, char* pcsubst);

//== получить длину подстроки
extern "C" int    __declspec(impexp) __stdcall
    substLen(char* pc, int nom_sub );

//-- заменить подстроку на новое значение в нужном месте строки
extern "C" int    __declspec(impexp) __stdcall
	setSubst(char* pc, char* pcres, int res_size, int nom_sub, char* pcsubst);

//-- очистить подстроку (заменить на пустое значение )
extern "C" int    __declspec(impexp) __stdcall
    clearSubst(char* pc, int nom_sub );

//-- полностью удалить подстроку
extern "C" int    __declspec(impexp) __stdcall
    cutSubst(char* pc, int nom_sub );

//-- удалить все подстроки перед заданой
extern "C" int    __declspec(impexp) __stdcall
    cutLeft(char* pc, int nom_sub );

//-- удалить все подстроки начиная с заданой
extern "C" int    __declspec(impexp) __stdcall
    cutRight(char* pc, int nom_sub );

//-- объединить подстроку с предидущей
extern "C" int    __declspec(impexp) __stdcall
    uniteSubst(char* pc, int nom_sub );




//==  получить начальную строку текста( заголовок)
extern "C" int    __declspec(impexp) __stdcall  getTextHead(char* pc, char* pcbuf, int bufsize);

//==  получить остаток текста без начальной строки( заголовка )
extern "C" int    __declspec(impexp) __stdcall  getTextBody(char* pc, char* pcbuf, int bufsize);

//-- запись целого числа в бинарный файл
extern "C" int    __declspec(impexp) __stdcall    fwriteInt( int fh, int val);

//-- чтение целого числа из бинарного файла
extern "C" int    __declspec(impexp) __stdcall    freadInt( int fh );

//== сосчитать число строк в тексте =
extern "C" int    __declspec(impexp) __stdcall    countTextSt(char* pc);

//== получить строку с заданным номером из текста
extern "C" int  __declspec(impexp) __stdcall    getTextSt(char* pc, char* pcbuf, int bufsize,  int st_nom);

//== Считать Смещение текущего фрагмента базы DBSN 
extern "C" int    __declspec(impexp) __stdcall    getFragmOffset( int  dbhadr,  int &rec_offset );

//== Считать Длину  текущего фрагмента базы DBSN
extern "C" int    __declspec(impexp) __stdcall    getFragmSize( int  dbhadr, int &rec_size );

//== проверить активна ли запись
extern "C" int    __declspec(impexp) __stdcall    isActive( int dbhadr );

//==  получить  признак ошибки DBSN
extern "C" int    __declspec(impexp) __stdcall    getErrCod( int dbhadr );

//== очистить признак ошибки
extern "C" int    __declspec(impexp) __stdcall    clearError( int dbhadr );

//-- новая функция ----
extern "C" char*    __declspec(impexp) __stdcall  trim( char* pc, char* pcres);

//== создать пустую базу фрагментов по имени файла
extern "C" int    __declspec(impexp) __stdcall     createDBSN( char*  fil_name );

//== проверить существование файлов DBSN
extern "C" int    __declspec(impexp) __stdcall     existDBSN( char*  fil_name );

//== получить все содержимое DBS файла
extern "C" int    __declspec(impexp) __stdcall  getAllDBS( char* fil_name, char* &text );

//== открыть базу фрагментов DBSN
extern "C" int   __declspec(impexp) __stdcall   openDBSN( char* fil_name );

//== Закрыть базу фрагментов DBSN
extern "C" int    __declspec(impexp) __stdcall  closeDBSN( int &dbhadr );

//==  Сосчитать число записей в Базе DBSN
extern "C" int    __declspec(impexp) __stdcall  countFragm( int dbhadr );

//== Удалить все фрагменты базы DBSN
extern "C" int    __declspec(impexp) __stdcall  delAllFragm(  int dbhadr );

//== Полностью уничтожить  базу DBSN
extern "C" int    __declspec(impexp) __stdcall  eraseDBSN( char*  fil_name);

//==  Переименовать базу DBSN в новое имя
extern "C" int    __declspec(impexp) __stdcall   renameDBSN( char*  old_fil, char*  new_fil );

//== Упаковать базу DBSN
extern "C" int    __declspec(impexp) __stdcall   packDBSN( char*  fil_name );

//== проверить на конец файла базу DBSN
extern "C" int    __declspec(impexp) __stdcall   isEndDBSN( int dbhadr );

//==  получить номер текущего фрагмента
extern "C" int    __declspec(impexp) __stdcall   getNom(int dbhadr );

//==  установить номер текущего фрагмента
extern "C" int    __declspec(impexp) __stdcall 	 setNom(int dbhadr, int new_nom );

//==  увеличить номер текущего фрагмента  
extern "C" int    __declspec(impexp) __stdcall   incNom(int dbhadr, int  count );

//==  уменьшить номер текущего фрагмента
extern "C" int    __declspec(impexp) __stdcall   decNom(int dbhadr, int  count );

//==  установить первый номер фрагмента
extern "C" int    __declspec(impexp) __stdcall   setFirst(int dbhadr );

//==  установить последний номер фрагмента
extern "C" int    __declspec(impexp) __stdcall   setLast(int dbhadr );

//== Считать текущий фрагмент базы DBSN  
extern "C" int    __declspec(impexp) __stdcall   getFragm(  int dbhadr, char* fragm,  int bufsize );

//==  Добавить запись в базу фрагментов DBSN
extern "C" int    __declspec(impexp) __stdcall
        addFragm( int dbhadr, char* fragm );

//==  Записать текст в текущую запись базы DBSN
extern "C" int    __declspec(impexp) __stdcall   
	setFragm(  int dbhadr, char*  fragm );

//== Удалить фрагмент базы DBSN с заданным номером
extern "C" int    __declspec(impexp) __stdcall   
	delFragm(  int dbhadr );

//== Снять признак удаления с фрагмента базы DBSN
extern "C" int    __declspec(impexp) __stdcall   
	undelFragm(  int dbhadr );

//== Сосчитать число блоков фрагментов базы DBSN
extern "C" int    __declspec(impexp) __stdcall   
	countBlocks( int dbhadr, int block_size, int flag_sel );

//== Извлечь заданный блок номеров фрагментов базы DBSN
extern "C" int    __declspec(impexp) __stdcall   
	getBlock( int dbhadr, int* pblock, int block_nom,  int block_size, int flag_sel  );


//== 20 янв 2014 ====
//-- сосчитать число подстрок в бинарной строке
extern "C" int    __declspec(impexp) __stdcall 
	binsubstCount( char* pcFragm, int fragmLen);

//-- получить смещение бинарной подстроки
extern "C" int    __declspec(impexp) __stdcall
	binsubstOffset(char* pcFragm, int fragmLen, long nom_sub);

//-- сосчитать длину подстроки в байтах по ее номеру
extern "C" int   __declspec(impexp)  __stdcall
	binsubstLen( char* pcFragm, int fragmLen, long nom_sub );

//-- сосчитать размер подстроки в словах по ее номеру
extern "C" int   __declspec(impexp)  __stdcall
	binsubstSize( char* pcFragm, int fragmLen, long nom_sub );

//-- вытащить бинарную подстроку с заданным номером из строки в буфер
extern "C" int   __declspec(impexp)  __stdcall
	getBinsubst(char* pcFragm, int fragmLen, char* pcBuf, int bufLen, long nom_sub);

//== добпвить к фрагменту бинарную подстроку
extern "C" int    __declspec(impexp) __stdcall
	addBinsubst( char* pcFragm, int fragmLen, char* pcBuf, int bufLen,  char* pcBinsubst );

//== вырезать бинарную подстроку из фрагмента
extern "C" int    __declspec(impexp) __stdcall
	cutBinsubst( char* pcFragm, int fragmLen, long nom_sub );

//== очистить бинарную подстроку  в фрагменте
extern "C" int    __declspec(impexp) __stdcall
    clearBinsubstIn( char* pcFragm, int fragmLen, long nom_sub );

//== вставить бинарную подстроку перед заданной во фрагмент
extern "C" int    __declspec(impexp) __stdcall
	insBinsubst( char* pcFragm, int fragmLen, char* pcBuf, int bufLen, long nom_sub, char* pcBinsubst );

extern "C" int    __declspec(impexp) __stdcall
	setBinsubst( char* pcFragm, int fragmLen, char* pcBuf, int bufLen, long nom_sub, char* pcBinSubst);


//==  Добавить Бин запись в базу фрагментов DBSN
extern "C" int    __declspec(impexp) __stdcall     
	addBinFragm( int dbhadr, char* fragm, int len_fragm );

//==  Записать Бин фрагмент в текущую запись базы DBSN
extern "C" int    __declspec(impexp) __stdcall   
	setBinFragm(  int dbhadr, char*  fragm, int len_fragm );

////////////////////////////////////////

//==  перейти к первому активному фрагменту
extern "C" int    __declspec(impexp) __stdcall
    gotoFirst( int dbhadr );

//==  перейти к следующему активному фрагменту
extern "C" int    __declspec(impexp) __stdcall
    gotoNext( int dbhadr, int count );

//==  перейти к предидущему активному фрагменту
extern "C" int    __declspec(impexp) __stdcall
    gotoPrev( int dbhadr, int count );

//==  перейти к последнему активному фрагменту
extern "C" int    __declspec(impexp) __stdcall
    gotoLast( int dbhadr );

//----------------------------------------------------------


extern "C" int*    __declspec(impexp) __stdcall
	writeBinRec( int dbhadr, int* plbuf);

extern "C" int*    __declspec(impexp) __stdcall 
	readBinRec( int dbhadr, int* plbuf);

extern "C" int    __declspec(impexp) __stdcall 
	xchgFragm( int  dbhadr, int  dest_nom );

extern "C" int    __declspec(impexp) __stdcall 
	flushDBSN( int  dbhadr );

//== Полностью вырезать данные фрагмента  из dbn
extern "C" int    __declspec(impexp) __stdcall
	cutFragm(  int dbhadr );

//==  Вставить запись в базу фрагментов DBSN в текущую позицию
extern "C" int    __declspec(impexp) __stdcall
	insFragm( int dbhadr, char* fragm);

//== Переместить текущий фрагмента в заданное место dbn
extern "C" int    __declspec(impexp) __stdcall
	moveFragm(  int dbhadr, int  dest_nom );

//== скопировать базу фрагментов под другим именем
extern "C" int    __declspec(impexp) __stdcall
	copyDBSN( char*  fil_name, char*  copy_filname, int flag_pack  );

//== дозаписать в буфер описание ошибки с комментарием
extern "C" int    __declspec(impexp) __stdcall
	getErrMes( int dbhadr, char* err_buf, int buf_len, char* comment);

//== работа со ссылками

//== создать ссылочный файл на таблицу фрагментов по имени файла
extern "C" int  __declspec(impexp) __stdcall createDBRF( char*  fil_name);

//== открыть ссылочный файл на таблицу фрагментов DBSN
extern "C" int  __declspec(impexp) __stdcall openDBRF( char* filref_name );

//== закрыть ссылочный файл на таблицу фрагментов DBSN
extern "C" int  __declspec(impexp) __stdcall closeDBRF( int fhr );

//== подсчитать количество записей в файле ссылое
extern "C" int  __declspec(impexp) __stdcall countRef( int fhr );

//== получить номер фрагмента по ссылке на него
extern "C" int   __declspec(impexp) __stdcall getFragmNomByRef(  int fhr, int ref_nom );

//== получить фрагмент по ссылке на него
extern "C" int   __declspec(impexp) __stdcall getFragmByRef(  int dbhadr, int fhr, int ref_nom,  char* fragm, int bufsize );

//== добавить в ссылочный файл номер фрагмента
extern "C" int   __declspec(impexp) __stdcall addFragmRef(  int fhr, int fragm_nom );

//== заменить в ссылочном файле номер фрагмента в нужной позиции
extern "C" int   __declspec(impexp) __stdcall setFragmRef(  int fhr, int ref_nom, int fragm_nom );

//== удалить в ссылочном файле номер фрагмента в нужной позиции
extern "C" int   __declspec(impexp) __stdcall delFragmRef(  int fhr, int ref_nom );

//== Снять удаление в ссылочном файле
extern "C" int   __declspec(impexp) __stdcall undelFragmRef(  int fhr, int ref_nom );

//== Поменять местами ссылки на фрагменты
extern "C" int    __declspec(impexp) __stdcall  xchgFragmRef( int  fhr, int  ref_nom1,  int ref_nom2 );

//==  вырезать физически в ссылочном файле номер фрагмента в нужной позиции
extern "C" int   __declspec(impexp) __stdcall cutFragmRef(  int fhr, int ref_nom );

//== вставить в ссылочном файле номер фрагмента в нужной позиции
extern "C" int   __declspec(impexp) __stdcall insFragmRef(  int fhr, int ref_nom, int fragm_nom );

//== установить новое число в заданное место нужной бинарной подстроки
extern "C" int   __declspec(impexp) __stdcall
    setBinnum(char* pcFragm, int fragmLen, long nom_sub, long nom_num, long src );

//== получить число с заданным номером из нужной бинарной подстроки
extern "C" int   __declspec(impexp) __stdcall
    getBinnum(char* pcFragm, int fragmLen, long nom_sub, long nom_num, long &dst );

//== удалить число с заданным номером из нужной бинарной подстроки
extern "C" int   __declspec(impexp) __stdcall
    cutBinnum(char* pcFragm, int fragmLen, long nom_sub, long nom_num );

//== добавить новое число в конец нужной бинарной подстроки
extern "C" int   __declspec(impexp) __stdcall
    addBinnum(char* pcFragm, int fragmLen, char* pcBuf, int lenBuf, long nom_sub, long src );

//== вставить новое число в заданное место нужной бинарной подстроки
extern "C" int   __declspec(impexp) __stdcall
    insBinnum(char* pcFragm, int fragmLen, char* pcBuf, int lenBuf, long nom_sub, long nom_num, long src );

//== поменять местами 2 числа в нужной бинарной подстроке
extern "C" int   __declspec(impexp) __stdcall
    chgBinnum(char* pcFragm, int fragmLen, long nom_sub, long nom_num1, long nom_num2 );

//== разбить DBS файл на фрагменты по ключевому слову
extern "C" int   __declspec(impexp) __stdcall
	formDBSN( char* txtFile, char* keyWord);

#endif
