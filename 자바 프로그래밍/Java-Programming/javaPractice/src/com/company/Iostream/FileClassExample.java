package com.company.Iostream;

import java.io.File;

public class FileClassExample {
    public static void listDirectory(File dir) {
        System.out.println("-----------" + dir.getPath() + "의 서브 리스트 입니다.-----------");
        File[] subFiles = dir.listFiles();

        for(int i = 0; i < subFiles.length; i++) {
            File f = subFiles[i];
            long t = f.lastModified(); // 마지막으로 수정된 시간

            System.out.print(f.getName());
            System.out.print("\t파일 크기: " + f.length());
            System.out.printf("\t수정한 시간: %tb %td %ta %tT\n", t, t, t, t);
        }
    }
    public static void main(String[] args) {
        File f1 = new File("./test.txt");
        System.out.println(f1.getPath() + ", " + f1.getParent() + ", " + f1.getName());

        String res = "";
        if(f1.isFile()) {
            res = "파일";
        } else if(f1.isDirectory()) {
            res = "디렉토리";
        }

        System.out.println(f1.getPath() + "은 " + res + "입니다.");

        File f2 = new File("./src/com/company/java_sample");
        if(!f2.exists()) {
            f2.mkdir();
        }

        listDirectory(new File("./src/com/company"));
    }
}

//./test.txt, ., test.txt
//./test.txt은 파일입니다.
//-----------./src/com/company의 서브 리스트 입니다.-----------
//Interface	파일 크기: 352	수정한 시간: 4월 13 수 21:59:37
//Collection	파일 크기: 416	수정한 시간: 4월 07 목 11:21:58
//Week.java	파일 크기: 135	수정한 시간: 3월 09 수 16:21:33
//BasicAPI	파일 크기: 1312	수정한 시간: 3월 31 목 16:30:07
//Swing	파일 크기: 288	수정한 시간: 4월 21 목 11:24:00
//java_sample	파일 크기: 64	수정한 시간: 5월 26 목 10:20:31
//double2	파일 크기: 352	수정한 시간: 3월 17 목 11:00:30
//SwingEvent	파일 크기: 256	수정한 시간: 4월 28 목 10:42:40
//Inheritance	파일 크기: 256	수정한 시간: 3월 09 수 22:55:40
//Main.java	파일 크기: 97	수정한 시간: 3월 09 수 20:16:00
//Array.java	파일 크기: 1967	수정한 시간: 3월 09 수 16:46:37
//Iostream	파일 크기: 224	수정한 시간: 5월 26 목 10:20:53
//Class	파일 크기: 224	수정한 시간: 3월 09 수 21:09:57
//Thread	파일 크기: 512	수정한 시간: 5월 21 토 15:36:29
//Exception	파일 크기: 384	수정한 시간: 3월 24 목 10:13:18
//JComponent	파일 크기: 384	수정한 시간: 5월 12 목 11:20:55
