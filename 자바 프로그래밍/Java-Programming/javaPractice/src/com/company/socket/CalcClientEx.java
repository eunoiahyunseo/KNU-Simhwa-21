package com.company.socket;

import java.io.*;
import java.net.Socket;
import java.util.Scanner;

public class CalcClientEx {
    public static void main(String[] args) {
        BufferedReader in = null;
        BufferedWriter out = null;
        Socket socket = null;
        Scanner scanner = new Scanner(System.in);
        try {
            socket = new Socket("localhost", 9999);
            in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
            out = new BufferedWriter(new OutputStreamWriter(socket.getOutputStream()));
            while(true) {
                System.out.println("계산식(빈칸으로 띄어 입력, 예: 24 42) >>");
                String outputMessage = scanner.nextLine();

                if(outputMessage.equalsIgnoreCase("Bye")) {
                    out.write(outputMessage + "\n");
                    out.flush();
                    break;
                }

                // server로 input으로 받은 문자열을 넘겨준다.
                out.write(outputMessage + "\n");
                out.flush();


                String inputMessage = in.readLine();
                System.out.println("계산 결과 " + inputMessage);
            }
        } catch(IOException e) {
            System.out.println(e.getMessage());
        } finally {
            try {
                scanner.close();
                if(socket != null) socket.close();
            } catch(IOException e) {
                System.out.println("서버와 채팅 중 오류가 발생했습니다.");
            }
        }
    }
}
