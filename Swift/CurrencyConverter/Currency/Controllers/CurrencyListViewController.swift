//
//  CurrencyListViewController.swift
//  Currency
//
//  Created by Macbook on 15.02.22.
//

import UIKit

enum ButtonType {
    case left
    case right
}

final class CurrencyListViewController: UIViewController {
    
    //MARK: - IBOutlets
    
    @IBOutlet weak var tableView: UITableView!
    
    //MARK: - Properties
    
    private var currencyData: [String] = []
    private let defaults = UserDefaults.standard
    public var buttonType: ButtonType = .left
    weak var delegate: ButtonHandler?
    
    //MARK: - ViewDidLoad
    
    override func viewDidLoad() {
        super.viewDidLoad()
        config()
    }
    
    //MARK: - Private functions
    
    private func config() {
        title = Constants.nameForTitle
        getDataFromUserDefaults()
        configTableView()
    }
    
    private func getDataFromUserDefaults() {
        guard let data = defaults.value(forKey: Constants.keyForDataSave) as? Data else { return }
        let decoder = JSONDecoder()
        do {
            let decodedData = try decoder.decode(CurrencyData.self, from: data)
            currencyData.append(contentsOf: decodedData.rates.keys)
        } catch {
            print("Bad data")
        }
    }
    
    private func configTableView() {
        tableView.delegate = self
        tableView.dataSource = self
        let nib = UINib(nibName: Constants.tableViewCellID, bundle: nil)
        tableView.register(nib, forCellReuseIdentifier: Constants.tableViewCellID)
    }
}

//MARK: - Extensions

extension CurrencyListViewController: UITableViewDelegate, UITableViewDataSource {
    
    func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return currencyData.count
    }
    
    func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        guard let cell = tableView.dequeueReusableCell(withIdentifier: Constants.tableViewCellID, for: indexPath) as? TableViewCell else { return UITableViewCell() }
        cell.codeLabel.text = currencyData[indexPath.row]
        if let image = UIImage(named: currencyData[indexPath.row]) {
            cell.flagImage.image = image
        } else {
            cell.flagImage.image = UIImage(named: "no_image")
        }
        return cell
    }
    
    func tableView(_ tableView: UITableView, didSelectRowAt indexPath: IndexPath) {
        switch buttonType {
        case .left:
            delegate?.didSelect(key: currencyData[indexPath.row], button: .left)
        case .right:
            delegate?.didSelect(key: currencyData[indexPath.row], button: .right)
        }
        navigationController?.popViewController(animated: true)
    }
}
