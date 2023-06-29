package com.company.Iostream;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;

public class BlockBinaryCopy {
    public static void main(String[] args) throws Exception{
        File src = new File("./images/img.jpg");
        File dest = new File("./src/com/company/iostream/img.jpg");

        FileInputStream fi = new FileInputStream(src); // 파일 입력 바이트 스트림 생성
        FileOutputStream fo = new FileOutputStream(dest); // 파일 출력 바이트 스트림 생성
        byte[] buf = new byte [1024 * 10]; // 10K버퍼
        while(true) {
            System.out.println("doing");
            int n = fi.read(buf); // 버퍼 크기만큼 읽기. n은 실제 읽은 바이트
            fo.write(buf, 0, n);
            if(n < buf.length) break;
        }

        fi.close();
        fo.close();
        System.out.println(src.getPath() + "를 " + dest.getPath() + "로 복사하였습니다.");
    }
}

//doing
//doing
//doing
//doing
//doing
//./images/img.jpg를 ./src/com/company/iostream/img.jpg로 복사하였습니다.