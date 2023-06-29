package com.company.Iostream;

import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;

public class TextCopy {
    public static void main(String[] args) throws Exception{
        File src = new File("./test.txt");
        File dest = new File("./src/com/company/iostream/test.txt");

        int c;
        FileReader fr = new FileReader(src); // 파일 입력 문자 스트림 생성
        FileWriter fw = new FileWriter(dest); // 파일 출력 문자 스트림 생성

        while((c = fr.read()) != -1) { // 문자 하나 읽고
            fw.write((char)c); // 문자 하나 쓰고
        }

        fr.close();
        fw.close();
        System.out.println(src.getPath() + "를 " + dest.getPath() + "로 복사하였습니다.");
    }
}
