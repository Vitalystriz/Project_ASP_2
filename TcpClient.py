import socket
import sys

def main():

    if len(sys.argv) != 3:
        print("Try again, using this format: python client.py <IP> <PORT>")
        return

    dest_ip = sys.argv[1]
    dest_port = int(sys.argv[2])


    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    s.connect((dest_ip, dest_port))

    while True:
        try:
        
            msg = input()
            msg += "\n"
            s.send(bytes(msg, 'utf-8'))
            data = s.recv(4096)
            if not data:
                break
            print(data.decode('utf-8'), end='')

        except EOFError:
            break
    s.close()
if __name__ == "__main__":
    main()