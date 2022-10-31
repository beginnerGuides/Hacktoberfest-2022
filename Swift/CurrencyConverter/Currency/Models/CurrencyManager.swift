//
//  CurrencyManager.swift
//  Currency
//
//  Created by Macbook on 16.02.22.
//

import UIKit

protocol CurrencyManagerDelegate {
    func didFailWithError(error: String)
}

struct CurrencyManager {
    
    var delegate: CurrencyManagerDelegate?
    var defaults = UserDefaults.standard
    
    func fetchJSON() {
        guard let url = URL(string: Constants.urlString) else { return }
        URLSession.shared.dataTask(with: url) { data, response, error in
            if let error = error {
                delegate?.didFailWithError(error: error.localizedDescription)
                return
            }
            guard let safeData = data else {
                delegate?.didFailWithError(error: "No available Data")
                return
            }
            saveData(safeData)
        }.resume()
    }
    
   private func saveData(_ data: Data) {
        defaults.setValue(data, forKey: Constants.keyForDataSave)
        return
    }
}
