//
//  CurrencyData.swift
//  Currency
//
//  Created by Macbook on 16.02.22.
//

struct CurrencyData: Codable {
    let base_code: String
    var rates: [String: Double]
}

