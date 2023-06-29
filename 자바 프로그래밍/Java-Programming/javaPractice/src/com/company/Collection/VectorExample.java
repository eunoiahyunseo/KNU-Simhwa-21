package com.company.Collection;

import java.util.*;
public class VectorExample {
    public static void main(String[] args) {
        List<Board> list = new Vector<>();

        list.add(new Board("제목1", "제목2", "글쓴이1"));
        list.add(new Board("제목2", "제목2", "글쓴이2"));
        list.add(new Board("제목3", "제목3", "글쓴이3"));
        list.add(new Board("제목4", "제목4", "글쓴이4"));
        list.add(new Board("제목5", "제목5", "글쓴이5"));

        list.remove(2);
        list.remove(3);

        for(int i = 0; i < list.size(); i++) {
            Board board = list.get(i);
            System.out.println(board.subject + "\t" + board.content + "\t" + board.writer);
        }
    }
}

//제목1	제목2	글쓴이1
//제목2	제목2	글쓴이2
//제목4	제목4	글쓴이4