package com.company.socket;

import java.io.*;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.Scanner;
import java.util.StringTokenizer;

public class CalcServerEx {
    public static String calc(String exp) {
        StringTokenizer st = new StringTokenizer(exp, " ");
        if(st.countTokens() != 3) return "error";
        String res = "";
        int op1 = Integer.parseInt(st.nextToken());
        String opcode = st.nextToken();
        int op2 = Integer.parseInt(st.nextToken());
        switch(opcode) {
            case "+":
                res = Integer.toString(op1 + op2);
                break;
            case "-":
                res = Integer.toString(op1 - op2);
                break;
            case "*":
                res = Integer.toString(op1 * op2);
                break;
            default:
                res = "error";
        }
        return res;
    }

    public static void main(String[] args) {
        BufferedReader in = null;
        BufferedWriter out = null;
        ServerSocket listener = null;
        Socket socket = null;

        try {
            listener = new ServerSocket(9999);
            System.out.println("연결을 기다리고 있었습니다.....");
            socket = listener.accept(); // 클라이언트로부터 연결 요청 대기
            System.out.println("연결되었습니다.");
            in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
            out = new BufferedWriter(new OutputStreamWriter(socket.getOutputStream()));

            while(true) {
                String inputMessage = in.readLine();
                if(inputMessage.equalsIgnoreCase("bye")) {
                    System.out.println("클라이언트에서 연결을 종료하였음");
                    break;
                }
//                System.out.println(inputMessage);
                StringTokenizer st = new StringTokenizer(inputMessage, " ");
                String res = "";
                int op1 = Integer.parseInt(st.nextToken());
                int op2 = Integer.parseInt(st.nextToken());
                res = Integer.toString(op1 + op2);
                out.write(res + "\n");
                out.flush();
            }
        } catch(IOException e) {
            System.out.println(e.getMessage());
        } finally {
            try {
                if(socket != null) socket.close(); // 통신용 소켓 닫기
                if(listener != null) listener.close(); // 서버 소켓 닫기
            } catch(IOException e) {
                System.out.println("클라이언트와 채팅 중 오류가 발생했습니다.");
            }
        }
    }
}
