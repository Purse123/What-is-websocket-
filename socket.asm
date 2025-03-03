section .data
    sockaddr_in:
        .sin_family   dw 2          ; AF_INET (2)
        .sin_port     dw 0x901F     ; Port 8080 (big-endian)
        .sin_addr     dd 0          ; INADDR_ANY (0.0.0.0)
        .sin_zero     dq 0          ; Padding (8 bytes)

    http_response db "HTTP/1.1 200 OK", 13, 10
                  db "Content-Type: text/html", 13, 10
                  db "Content-Length: 39", 13, 10
                  db 13, 10
                  db "<html><body><h1>Hello, World!</h1></body></html>", 0
    response_length equ $ - http_response  ; Compute response size

section .bss
    sock resq 1                    ; Reserve space for socket descriptor
    client resq 1                  ; Reserve space for client socket

section .text
    global _start

_start:
    ; Step 1: Create socket
    mov rax, 41        ; syscall: sys_socket
    mov rdi, 2         ; AF_INET
    mov rsi, 1         ; SOCK_STREAM
    xor rdx, rdx       ; Protocol = 0
    syscall
    mov [sock], rax    ; Save socket descriptor

    ; Step 2: Bind socket
    mov rdi, [sock]    
    lea rsi, [sockaddr_in]  
    mov rdx, 16        
    mov rax, 49        
    syscall

    ; Step 3: Listen
    mov rdi, [sock]    
    mov rsi, 5         
    mov rax, 50        
    syscall

_accept_loop:
    ; Step 4: Accept connection
    mov rdi, [sock]
    xor rsi, rsi       
    xor rdx, rdx       
    mov rax, 43        
    syscall            
    mov [client], rax  

    ; Step 5: Send HTTP Response
    mov rdi, [client]  
    mov rsi, http_response
    mov rdx, response_length
    mov rax, 44        
    syscall            

    ; Step 6: Close client socket
    mov rdi, [client]  
    mov rax, 3         
    syscall            

    jmp _accept_loop   ; Keep accepting connections

