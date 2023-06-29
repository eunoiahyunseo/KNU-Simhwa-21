package com.company.socket;

import java.io.*;
import java.net.InetAddress;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.Scanner;

public class ServerEx2 {
    public static void main(String[] args) {
        ServerSocket listener = null;
        Socket socket = null;
        BufferedReader in = null;
        BufferedWriter out = null;
        InetAddress address = null;
        Scanner scanner = new Scanner(System.in);
        try {
            listener = new ServerSocket(9999);
            address = listener.getInetAddress();
            System.out.println("address >> " + address);
            System.out.println("연결 기다림...");
            socket = listener.accept();
            System.out.println("연결 되었음");
            in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
            out = new BufferedWriter(new OutputStreamWriter(socket.getOutputStream()));
            while(true) {
                // 즐 단위로 수신하게 된다. ( 클라이언트로 부터 온 메시지를 )
                String inputMessage = in.readLine();
                System.out.println("데이터 받기 성공");
                if(inputMessage.equalsIgnoreCase("bye")) {
                    System.out.println("클라이언트에서 연결을 종료했음");
                    break;
                }
                System.out.println("클랴이언트: " + inputMessage);

                //----------------------------------------
                System.out.println("보내기 >>");
                String outputMessage = scanner.nextLine();
                out.write(outputMessage + "\n");
                out.flush();
            }
        } catch(IOException e) {}

        try {
            listener.close();
            socket.close();
        } catch(Exception e) {}
    }
}
