//
//  ProductRow.swift
//  FruitMart
//
//  Created by Giftbot on 2020/03/02.
//  Copyright © 2020 Giftbot. All rights reserved.
//

import SwiftUI

struct ProductRow: View {
  @EnvironmentObject var store: Store
  let product: Product
  @Binding var quickOrder: Product?
  
  // MARK: Body
  
  var body: some View {
    HStack {
      productImage
      productDescription
    }
    .frame(height: 150)
    .background(Color.primary.colorInvert())
    .cornerRadius(6)
    .shadow(color: .primaryShadow, radius: 1, x: 2, y: 2)
    .padding(.vertical, 8)
  }
}


private extension ProductRow {
  // MARK: View
  
  var productImage: some View {
    ResizedImage(product.imageName)
      .frame(width: 140)
      .clipped()
  }
  
  var productDescription: some View {
    VStack(alignment: .leading) {
      Text(product.name)
        .font(.headline)
        .fontWeight(.medium)
        .padding(.bottom, 6)
      
      Text(product.description)
        .font(.footnote)
        .foregroundColor(.secondaryText)
      
      Spacer()
      
      footerView
    }
    .padding([.leading, .bottom], 12)
    .padding([.top, .trailing])
  }
  
  var footerView: some View {
    HStack(spacing: 0) {
      Text("₩").font(.footnote)
        + Text("\(product.price)").font(.headline)
      
      Spacer()
      
      FavoriteButton(product: product)
      
      Symbol("cart", color: .peach)
        .frame(width: 32, height: 32)
        .onTapGesture { self.orderProduct() }
    }
  }
  
  // MARK: Action
  
  private func orderProduct() {
    quickOrder = product
    store.placeOrder(product: product, quantity: 1)
  }
}


// MARK: - Previews

struct ProductRow_Previews: PreviewProvider {
  static var previews: some View {
    Group {
      ForEach(productSamples) {
        ProductRow(product: $0, quickOrder: .constant(nil))
      }
      ProductRow(product: productSamples[0], quickOrder: .constant(nil))
        .preferredColorScheme(.dark)
    }
    .padding()
    .previewLayout(.sizeThatFits)
  }
}
