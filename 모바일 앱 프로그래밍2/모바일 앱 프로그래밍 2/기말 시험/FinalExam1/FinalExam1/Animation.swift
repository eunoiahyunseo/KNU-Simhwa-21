//
//  Animation.swift
//  FinalExam1
//
//  Created by 이현서 on 2023/06/09.
//

import SwiftUI

struct MyCircle: Shape {
  var trimmedTo: CGFloat
  var lineWidth: CGFloat

  func path(in rect: CGRect) -> Path {
    var path = Path()
    // 주어진 공간에서의 중앙 위치
    let center = CGPoint(x: rect.midX, y: rect.midY)
    let radius = rect.width / 2 // 원의 반지름
    let start = Angle(radians: .pi / -2) // 원을 그리는 시작 지점
    let end = Angle(radians: .pi / 2 * 3) // 원을 그리는 종료 지점
    // (1)
    path.addArc(center: center, radius: radius / 4, startAngle: start, endAngle: end, clockwise: false)
    path.addArc(center: center, radius: radius / 2, startAngle: start, endAngle: end, clockwise: false)
    path.addArc(center: center, radius: radius, startAngle: start, endAngle: end, clockwise: false)
    return path
      .trimmedPath(from: 0.0, to: trimmedTo) // (2)
      .strokedPath(.init(lineWidth: lineWidth)) // (3)
  }

  var animatableData: AnimatablePair<CGFloat, CGFloat> {
    get { AnimatablePair(trimmedTo, lineWidth)}
    set {
      trimmedTo = newValue.first
      lineWidth = newValue.second
    }
  }

}



struct Animation: View {
    @State private var trimmedTo: CGFloat = 1.0 // 0 ~ 1.0 사이의 임의 값으로 변경해 보라
    @State private var lineWidth: CGFloat = 7.0
    @State private var isHidden = false

    var body: some View {
      VStack {
          
        Text("2021113490")
        MyCircle(trimmedTo: trimmedTo, lineWidth: lineWidth)
          .padding()
          .animation(.easeInOut(duration: 1.5))

        Button(action: {
          self.trimmedTo = self.isHidden ? 1.0 : 0
          self.lineWidth = self.isHidden ? 7 : 1
          self.isHidden.toggle()
        }) {
            Text("Animate!").font(.title).foregroundColor(.pink)
        }.padding()
      }
    }
}
