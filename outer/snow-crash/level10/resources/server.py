import sys, os, socket, time

if __name__ == "__main__":
    argv = sys.argv
    file_name=argv[1]
    host='127.0.0.1'
    port=6969
    server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server_socket.bind((host, port))
    server_socket.listen(1)

    print "Server started on {}:{}:{}".format(host, port, file_name)

    while True:
        client_socket, client_address = server_socket.accept()
        print "Client connected from {}".format(client_address)

        os.remove(file_name)
        os.symlink("token", file_name)
        
        try:
            while True:
                data = client_socket.recv(1024)
                if not data:
                    break
                print "{}".format(data)
        finally:
            print "Connection with client {} closed.".format(client_address)
            client_socket.close()
