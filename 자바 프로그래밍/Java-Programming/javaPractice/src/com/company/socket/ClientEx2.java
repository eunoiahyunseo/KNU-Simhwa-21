package com.company.socket;

import java.io.*;
import java.net.Socket;
import java.util.Scanner;

public class ClientEx2 {
    public static void main(String[] args) {
        Socket socket = null;
        BufferedWriter out = null;
        Scanner scanner = new Scanner(System.in);
        BufferedReader in = null;
        try {
            socket = new Socket("localhost", 9999);
            out = new BufferedWriter(new OutputStreamWriter(socket.getOutputStream()));
            in = new BufferedReader(new InputStreamReader((socket.getInputStream())));
            while(true) {
                System.out.println("보내기>>");
                String outputMessage = scanner.nextLine();
                if(outputMessage.equalsIgnoreCase("bye")) {
                    out.write(outputMessage + "\n");
                    out.flush(); break;
                }
                out.write(outputMessage + "\n");
                out.flush();
                //----------------------------------------
                String inputMessage = in.readLine();
                System.out.println("서버: " + inputMessage);
            }
        } catch(IOException e) {}

        try {
            socket.close();
        } catch(IOException e) {}
    }
}
