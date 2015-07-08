                                      /* Example socket code - find a free port
                                                         * technion@lolware.net
                                                                    * 10/2/2015
                                         * Example only - not production tested
                                                                             */
                                                             #include <stdio.h>
                                                        #include <sys/socket.h>
                                                         #include <arpa/inet.h>
                                                            #include <string.h>
                                                             #ifndef S_SPLINT_S
                                                            #include <unistd.h>
                                                                         #endif
                                                            #include <stdlib.h>
                                                             #include <errno.h>
                                                                                
         #define STARTPORT 8081 /* Start port range to check for a free port */
                                                          #define ENDPOINT 8090
                                                                                
                                      static uint16_t bind_open_port(int sock);
                                                                                
                                                                     int main()
                                                                          {
                                                                  int sock;
                                                             uint16_t port;
                                                                            
                                   /* Generic socket creation, ipv4, TCP */
                          sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
                                                        if (sock < 0) {
                                     perror("Failed to create socket");
                                                    exit(EXIT_FAILURE);
                                                                          }
                                                                            
                                               port = bind_open_port(sock);
                         printf("Successfully bound to socket %d\n", port);
                                                         (void)close(sock);
                                                                            
                                                                  return 0;
                                                                              }
                                                                                
               /* Cycles from STARTPORT to ENDPORT, looking for a port that is 
                                                        * available for bind().
                                                       * int sock: Valid socket
                                         * Returns: port number, or 0 for error
                                                                             */
                                                                                
                                       static uint16_t bind_open_port(int sock)
                                                                          {
                                               struct sockaddr_in servAddr;
                                                             uint16_t port;
                                                                            
                      for(port = STARTPORT; port <= ENDPOINT; port++) {
                                memset(&servAddr, 0, sizeof(servAddr));
                                         servAddr.sin_family = AF_INET;
                          servAddr.sin_addr.s_addr = htonl(INADDR_ANY);
                                       servAddr.sin_port = htons(port);
                         if (bind(sock, (struct sockaddr *) &servAddr, 
                               (socklen_t)sizeof(servAddr)) == 0) {
                                              /* Successful bind */
                                                       return port;
                                                                      }
                                        /* Error condition on bind() */
                                          if(errno == EADDRINUSE) {
        /* This is the "port in use" error, try for another port */
                               printf("Port %d is in use\n", port);
                                                          continue;
                                                                      }
                        /* Reaching here indicates a different error */
                                              perror("Failed to bind");
                                                                          }
                                     printf("Unable to find a valid port");
                                                                  return 0;
                                                                            
                                                                              }
                                                                                
