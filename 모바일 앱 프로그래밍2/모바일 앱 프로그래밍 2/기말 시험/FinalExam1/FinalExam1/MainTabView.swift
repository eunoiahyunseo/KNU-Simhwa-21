//
//  MainTabView.swift
//  FinalExam1
//
//  Created by 이현서 on 2023/06/09.
//

import SwiftUI

struct MainTabView: View {
    private enum Tabs {
        case tabA, tabB, tabC
    }
    
    
    @State private var selectedTab: Tabs = .tabA
    let game = EmojiMemoryGame()
    
    var body: some View {
        TabView(selection: $selectedTab) {
            Group {
                tabA
                tabB
                tabC
            }
            .accentColor(.primary)
        }
        .accentColor(.red)
        .onAppear {
            UITabBar.appearance().backgroundColor = UIColor.systemGray3
            UITabBar.appearance().unselectedItemTintColor = UIColor.systemGray
        }
    }
}

private extension MainTabView {
    var tabA: some View {
        return ContentView(viewModel: game)
            .tag(Tabs.tabA)
            .tabItem {
                Image(systemName: selectedTab != Tabs.tabA
                        ? "a.square.fill"
                        : "a.circle.fill")
            }
            
    }
    
    var tabB: some View {
        Animation()
            .tag(Tabs.tabB)
            .tabItem {
                Image(systemName: selectedTab != Tabs.tabB
                        ? "b.square.fill"
                        : "b.circle.fill")
            }
    }
    
    var tabC: some View {
        VStack {
            Text("태그 C")
                .font(.system(size: 32))
                .fontWeight(.bold)
                
                
            Text("2021113490")
        }
        .tag(Tabs.tabC)
        .tabItem {
            Image(systemName: selectedTab != Tabs.tabC
                  ? "c.square.fill"
                  : "c.circle.fill")
        }
    }
    
}
struct MainTabView_Previews: PreviewProvider {
    static var previews: some View {
        MainTabView()
    }
}
