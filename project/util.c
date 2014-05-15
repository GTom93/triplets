/**
 * Triplets Game - VIOPE 2014
 *
 * @creation date	2014-03-27
 *
 **/

/*=====================================
 * System includes
 *===================================*/

#include <stdio.h>
#include <winsock2.h>
#ifdef _WIN32

#include <Windows.h>

#endif

#ifdef linux

#include <time.h>

#endif

/*=====================================
 * Local includes
 *===================================*/
#include "util.h"

/*=====================================
 * Prototypes of **private** functions
 *===================================*/

/*=====================================
 * Public functions
 *===================================*/

void getDate(char dateExtended[]);

/**
 * Brief description of the function
 *
 * @v info_s	string hold with some info
 * @return	what does this function returns
 * @date	2014-03-27
 * @author	name of the author of the function
 **/

void getDate(char dateExtended[])
{

#ifdef _WIN32
    SYSTEMTIME str_t;
    GetSystemTime(&str_t);

//	printf("Date: %d/%d/%d f%d:%d",str_t.wYear,str_t.wMonth,str_t.wDay,str_t.wHour,str_t.wMinute);

    sprintf(dateExtended, "%d/%d/%d-%d:%d", str_t.wYear, str_t.wMonth, str_t.wDay, str_t.wHour, str_t.wMinute);

#endif

#ifdef linux

    time_t currTime;
    struct tm *localTime;
    currTime = time(NULL);

    localTime = localtime (&currTime);

//    printf("Date: %s", asctime(localTime));

    strcpy(dateExtended, asctime(localTime));

#endif
}

/**
 * Brief description of the function
 *
 * @v info_s	Function that auto-opens .html file in default browser when we start the game.
 * @return	Nothing.
 * @date	2014-05-15
 * @author	Krzysztof Paliga, Tomasz Gradzinski
 **/

void OpenHTML(char* HTMLName)
{
    char command[100] = "open ";
    strcat(command,HTMLName);
    puts(command);
    #ifdef _WIN32
    system(HTMLName);
    #else
    write(command);
    #endif // linux
}

/**
 * Brief description of the function
 *
 * @v info_s	Function that starts listen server for JS sockets.
 * @return	Nothing.
 * @date	2014-05-15
 * @author	Krzysztof Paliga, Tomasz Gradzinski
 **/

 void startServer()
 {
    WSADATA wsaData;

    int result = WSAStartup( MAKEWORD( 2, 2 ), & wsaData );
    if( result != NO_ERROR )
        printf( "Initialization error.\n" );
    SOCKET mainSocket = socket( AF_INET, SOCK_STREAM, IPPROTO_TCP );
    if( mainSocket == INVALID_SOCKET )
    {
        printf( "Error creating socket: %d\n", WSAGetLastError() );
        WSACleanup();
        //return 1;
    }
    struct sockaddr_in service;
    memset( & service, 0, sizeof( service ) );
    service.sin_family = AF_INET;
    service.sin_addr.s_addr = inet_addr( "127.0.0.1" );
    service.sin_port = htons( 1234 );

    if( bind( mainSocket,( SOCKADDR * ) & service, sizeof( service ) ) == SOCKET_ERROR )
    {
        printf( "bind() failed.\n" );
        closesocket( mainSocket );
        //return 1;
    }
    if( listen( mainSocket, 1 ) == SOCKET_ERROR )
        printf( "Error listening on socket.\n" );

    SOCKET acceptSocket = SOCKET_ERROR;
    //printf( "Waiting for a client to connect...\n" );

    while( acceptSocket == SOCKET_ERROR )
    {
        acceptSocket = accept( mainSocket, NULL, NULL );
    }

    //printf( "Client connected.\n" );
    mainSocket = acceptSocket;

    if( connect( mainSocket,( SOCKADDR * ) & service, sizeof( service ) ) != SOCKET_ERROR )
    {
        printf( "Failed to connect.\n" );
        WSACleanup();
        //return 1;
    }

    int bytesSent;
    int bytesRecv = SOCKET_ERROR;
    char sendbuf[ 20 ] = "";
    char recvbuf[ 9 ] = "";
    char move[4] = "";
    bytesRecv = recv( mainSocket, recvbuf, 9, 0 );
    //printf( "Bytes received: %d\n", bytesRecv );
    //printf( "Received text: %s\n", recvbuf );

    bytesSent = send( mainSocket, sendbuf, strlen( sendbuf ), 0 );
    //printf( "Bytes sent: %d\n", bytesSent );
    WSACleanup();

    int a;
    int b=0;
    for (a=5;a<8;a++)
    {
        if((recvbuf[a] == '/') || (recvbuf[a] == ' '))
            continue;
        move[b] = recvbuf[a];
        b++;

        //printf("\n");
    }
    //printf("%s", move);

    FILE *mov = fopen("move.mv", "w+");
    fprintf(mov,"%s", move);
    fclose(mov);
 }

/*=====================================
 * Private functions
 *===================================*/

