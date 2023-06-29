package com.company;

public class Array {
    public void Array1() {
        String[] strArray = new String[3];
        strArray[0] = "Java";
        strArray[1] = "Java";
        strArray[2] = new String("Java");

        System.out.println(strArray[0] == strArray[1]); // true ( 같은 객체를 참조 )
        System.out.println(strArray[0] == strArray[2]); // false ( 다른 객체를 참조 )
        System.out.println(strArray[0].equals(strArray[2])); // true ( 문자열이 동일 )
    }

    public void Array2() {
        String[] oldStrArray = {"java", "array", "copy"};
        String[] newStrArray = new String[5];

        System.arraycopy(oldStrArray, 0, newStrArray, 0, oldStrArray.length);
        for(int i = 0; i < newStrArray.length; i++) {
            System.out.print(newStrArray[i] + ", ");
        }
    }

    public void Array3() {
        Integer[] scores = new Integer[]{95, 71, 84, 93, 87};

        int sum = 0;
        for(int score : scores) {
            sum += score;
        }

        System.out.println("점수 총합 = " + sum);

        double avg = (double) sum / scores.length;
        System.out.println("점수 평균 = " + avg);

    }

    public void Array4(String args) {
        Week today = Week.TUESDAY;

        String name = today.name();
        int ordinal = today.ordinal();

        int result1 = today.compareTo(Week.SUNDAY);

        System.out.println("today name >> " + name);
        System.out.println("today ordinal >> " + ordinal);
        System.out.println("today compare to SUNDAY >> " + result1);

        String strDay = args;
        Week weekDay = Week.valueOf(strDay);
        if(weekDay == Week.SATURDAY || weekDay == Week.SUNDAY) {
            System.out.println("주말 이군요!");
        } else {
            System.out.println("평일 이군요!");
        }

        Week[] days = Week.values();
        for(Week day : days) {
            System.out.println(day);
        }
    }
}
