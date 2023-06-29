//
//  ContentView.swift
//  Chapter07
//
//  Created by gsjung on 2023/05/13.
//

import SwiftUI

// 교재 p.393, chapter 07 p.4, 스크롤 뷰 방향에 따른 프레임 속성

struct ContentView: View {
  var body: some View {
    ScrollView(.vertical) {  // 세로축과 가로축을 바꿔서 비교
      Text("스크롤 뷰")
        .font(.largeTitle)
        .bold()
    }
    .background(Color.green)
  }
}


// 교재 p.394, chapter 07 p.5, 스크롤 뷰 방향에 따른 프레임 속성
/*
struct ContentView: View {
  var body: some View {
    
    GeometryReader { geometry in
      VStack {
        // 세로축 스크롤 뷰
        Text("Vertical ScrollView").font(.largeTitle)
        ScrollView {
          ForEach(0..<10) { i in
            Circle()
              .fill(Color(white: 0.2 + (0.8 * Double(i) / 10))) // 순서에 따라 색 변화
              .frame(width: 80, height: 80) // Circle의 크기
          }
          .frame(width: geometry.size.width / 2) // 스크롤 뷰 콘텐츠(ForEach)의 너비
        }
        .frame(height: geometry.size.height / 2) // 스크롤 뷰의 높이
        .padding(.bottom)
        
        // 가로축 스크롤 뷰
        Text("Horizontal ScrollView").font(.largeTitle)
        ScrollView(.horizontal) {
          HStack {
            ForEach(0..<10) { i in
              RoundedRectangle(cornerRadius: 10)
                .fill(Color.yellow)
                .frame(width: 100, height: 100) // RoundedRectangle의 크기
                .scaleEffect(1 - (0.7 * CGFloat(i) / 10)) // 순서에 따라 크기 변화
            }
          }
          .frame(height: geometry.size.height / 5) // 스크롤 뷰 콘텐츠(HStack)의 높이
          .padding(.horizontal)
        }
      }
    }
  }
}
*/



// 교재 pp.397 ~ 398, chapter 07 p.6, 스크롤 뷰의 콘텐츠 크기 특성

// VStack vs. 세로축 스크롤 뷰
/*
struct ContentView: View {
  var body: some View {
    VStack {
      Color.red
      Color.green
      Color.blue
    }
  }
}
*/

/*
struct ContentView: View {
  var body: some View {
    ScrollView {  // VStack과 비교
      Color.red
      Color.green
      Color.blue
    }
  }
}
*/


// HStack vs. 가로축 스크롤 뷰
/*
struct ContentView: View {
  var body: some View {
    HStack {
      Color.red
      Color.green
      Color.blue
    }
  }
}
*/

/*
struct ContentView: View {
  var body: some View {
    ScrollView(.horizontal) {  // HStack과 비교
      HStack {
        Color.red
        Color.green
        Color.blue
      }
    }
  }
}
*/


// 교재 pp.399 ~ 400, chapter 07 p.8, 세로축 스크롤 뷰와 같은 효과를 적용한 VStack
/*
struct ContentView: View {
  var body: some View {
    VStack {
      Color.red
      Color.green
      Color.blue
    }
    .fixedSize(horizontal: false, vertical: true) // 높이에 대해 idealHeight 적용
    .frame(maxHeight: .infinity, alignment: .top) // 세로축 스크롤 뷰처럼 세로 방향으로 최대한의 크기로 확장한 뒤 top 정렬
  }
}
*/

// 교재 p.400, chapter 07 p.9
// 세로축 스크롤 뷰의 자식 뷰의 idealHeight를 각각 다르게 지정한 경우
/*
struct ContentView: View {
  var body: some View {
    ScrollView {
      Color.red
      Color.green.frame(idealHeight: 30)
      Color.blue.frame(idealHeight: 200)
    }
  }
}
*/

// 교재 pp.402 ~ 403, chapter 07 pp.10 ~ 11, ContentOffset
// 스크롤 뷰에서 콘텐츠의 위치를 다루기 위해 GeometryReader의 글로벌 좌표를 이용해 값을 계산한다.
/*
struct ContentView: View {
  var body: some View {
    ScrollView {
      ForEach(0..<10) { _ in
        GeometryReader { // 스크롤 뷰 내부에서 지오메트리 리더 사용
          Rectangle()
            .fill(self.color(from: $0)) // 위치에 따라 색 변경
        }
        .frame(width: 150, height: 150) // 지오메트리 리더 크기
      }
    }
  }

  func color(from proxy: GeometryProxy) -> Color {
    // 글로벌 좌표를 스크롤 뷰 기준으로 변환하는 작업
    let yOffset = proxy.frame(in: .global).minY - 44
    let color = min(1, 0.2 + Double(yOffset / 1000)) // 0.2 ~ 1 사이의 값
    return Color(hue: color, saturation: color, brightness: color)
  }
}
*/


// 교재 p.404, chapter 07 p.12, 스크롤 뷰의 페이징 구현
/*
struct ContentView: View {
  var body: some View {
    let colors: [Color] = [.red, .green, .blue]
    return GeometryReader { proxy in
      ScrollView(.horizontal) {
        HStack(spacing: 0) { // 뷰 사이 간격을 0으로 지정
          ForEach(colors.indices) { index in // RGB 색에 맞춰 3개의 페이지 생성
            Circle()
              .fill(colors[index]) // 색 지정
              .overlay(Text("\(index) 페이지")) // 현재 페이지 표시
              .font(.largeTitle).foregroundColor(.white)
          }
          .frame(width: proxy.size.width, height: proxy.size.height) // 원형 크기
        }
      }
      // 페이징 기능 활성화
      .onAppear{ UIScrollView.appearance().isPagingEnabled = true }
    }
  }
}
*/

// 교재 p.406, chapter 07 p.14, TabView
/*
struct ContentView: View {
  var body: some View {
    TabView { // 탭 뷰를 선언하고 콘텐츠로 각각의 자식 뷰를 전달한다.
      VStack { // 첫 번째 탭 선택 시 보일 뷰
        Text("첫 번째 탭").font(.largeTitle)
        Image("SwiftUI")
      }.tabItem { // 첫 번째 탭 아이템
        Image(systemName: "house")
        Text("아이템1")
      }
      
      Text("두 번째 탭의 화면")  // 두 번째 탭 선택 시 보일 뷰
        .font(.title)
        .padding()
        .background(Color.yellow)
        .tabItem {
          Image(systemName: "cube")
          Text("아이템2")
        }
      
      SomeView()
        .tabItem {
          Image(systemName: "person")
          Text("아이템3")
        }
    }
  }

  struct SomeView: View {
    var body: some View {
      VStack {
        Text("실제로는 이런 식으로")
        Text("별도의 뷰를 만들어서 사용하겠죠.")
      }.font(.title)
    }
  }
}
*/

// 교재 p.409, chapter 07 p.17, TabView - tag

// 탭 뷰 사용 시 어떤 탭을 선택한 상태인지 알고 싶은 경우
/*
struct ContentView: View {
  @State private var selectedTab = 0 // 상태를 저장할 프로퍼티 정의
  var body: some View {
    TabView(selection: $selectedTab) { // 탭 뷰에서 선택한 값과 상태 프로퍼티 연동
      ForEach(0..<3) { index in
        Text("태그 \(index)").font(.largeTitle).fontWeight(.bold)
          .tag(index) // selectedTab의 값을 현재 선택된 index의 값으로 설정
          .tabItem {
            Image(systemName: selectedTab != index // 탭 선택 여부 확인
                  ? "\(index).square" // 탭이 선택되지 않았을 때 사용할 이미지
                  : "\(index).square.fill" // 탭이 선택되었을 때 사용할 이미지
            ).imageScale(.large)
          }
      }
    }
  }
}
*/


// 교재 p.409, chapter 07 p.19, TabView - tag

// SelectionValue로 사용할 수 있는 값은 Hashable 프로토콜을 준수하는 타입이면 무엇이든 가능하다.
/*
struct ContentView: View {
  enum TabItems {
    case A, B
  }
 
  @State private var selected = TabItems.A

  var body: some View {
    TabView(selection: $selected) {
      Text("A 뷰")
        .tag(TabItems.A)
        .tabItem { Image(systemName: "a.circle").imageScale(.large) }
      
      Text("B 뷰")
        .tag(TabItems.B)
        .tabItem { Image(systemName: "b.circle").imageScale(.large) }
    }
  }
}
*/

// 교재 p.409, chapter 07 p.20, TabView - 선택 아이템, 비선택 아이템, 배경 컬러 변경
/*
struct ContentView: View {
  @State private var selectedTab = 0 // 상태를 저장할 프로퍼티 정의
  var body: some View {
    TabView(selection: $selectedTab) { // 탭 뷰에서 선택한 값과 상태 프로퍼티 연동
      ForEach(0..<3) { index in
        Text("태그 \(index)").font(.largeTitle).fontWeight(.bold)
          .tag(index) // selectedTab의 값을 현재 선택된 index의 값으로 설정
          .tabItem {
            Image(systemName: selectedTab != index // 탭 선택 여부 확인
                  ? "\(index).square" // 탭이 선택되지 않았을 때 사용할 이미지
                  : "\(index).square.fill" // 탭이 선택되었을 때 사용할 이미지
            ).imageScale(.large)
          }
      }
    }
    .accentColor(.black) // 선택 아이템의 컬러 변경
    .onAppear {
      // 배경색과 미선택 아이템의 틴트 컬러 변경
      UITabBar.appearance().backgroundColor = UIColor.systemGray3
      UITabBar.appearance().unselectedItemTintColor = UIColor.systemGray
      
      // 탭 바의 틴트 컬러 변경 - iOS16에서 적용 안 됨
      //UITabBar.appearance().barTintColor = UIColor.red // iOS7부터 barTintColor 속성은 UIView로 옮겨짐
    }
  }
}
*/

struct ContentView_Previews: PreviewProvider {
    static var previews: some View {
      ContentView()
      //ContentView().preferredColorScheme(.dark)
    }
}
