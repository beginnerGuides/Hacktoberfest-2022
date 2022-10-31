//
//  ViewController.swift
//  Currency
//
//  Created by Macbook on 15.02.22.
//

import UIKit

protocol ButtonHandler: AnyObject {
    func didSelect(key: String, button: ButtonType)
}

class ConverterViewController: UIViewController {

    //MARK: - IBOutlets
    
    @IBOutlet weak var leftButton: UIButton!
    @IBOutlet weak var rightButton: UIButton!
    @IBOutlet weak var leftFlagImage: UIImageView!
    @IBOutlet weak var rightFlagImage: UIImageView!
    @IBOutlet weak var leftFlagButton: UIButton!
    @IBOutlet weak var rightFlagButton: UIButton!
    @IBOutlet weak var leftCurrencyLabel: UILabel!
    @IBOutlet weak var rightCurrencyLabel: UILabel!
    @IBOutlet weak var leftTextField: UITextField!
    @IBOutlet weak var rightTextField: UITextField!
    
    //MARK: - Properties
    
    public var currentTextLeftButton: String = ""
    public var currentTextRightButton: String = ""
    var manager = CurrencyManager()
    var data: CurrencyData?
    
    //MARK: - ViewDidLoad
    
    override func viewDidLoad() {
        super.viewDidLoad()
        config()
    }
    
    //MARK: - Private functionns
    
    private func config() {
        createDelegate()
        configTextFields()
        parseData()
    }
    
    private func parseData() {
        let decoder = JSONDecoder()
        let defaults = UserDefaults.standard
        guard let data = defaults.value(forKey: Constants.keyForDataSave) as? Data else { return }
        do {
            let decodedData = try decoder.decode(CurrencyData.self, from: data)
            self.data = decodedData
        } catch {
            print("Bad data")
        }
    }
    
    private func createDelegate() {
        manager.delegate = self
        leftTextField.delegate = self
        rightTextField.delegate = self
    }
    
    private func configTextFields() {
        leftTextField.tag = 1
        rightTextField.tag = 2
    }
    
    private func converter(left: Double, right: Double, tag: Int) -> String {
        guard left != 0,
              right != 0,
              let data = data
              else {return ""}
        switch tag {
        case 1:
            if leftCurrencyLabel.text == "USD" {
                if let value = data.rates[rightCurrencyLabel.text ?? ""] {
                    let result = String(format: "%.2f", left * value)
                    return result
                }
            }
        case 2:
            return ""
        default:
            return ""
        }
        return ""
    }
    
    //MARK: - IBActions
    
    @IBAction func leftFlagPressed(_ sender: UIButton) {
//        let storyboard = UIStoryboard(name: "Main", bundle: nil)
//        guard let controller = storyboard.instantiateViewController(withIdentifier: Constants.ListStoryboardID) as? CurrencyListViewController else { return }
//        controller.delegate = self
//        controller.buttonType = .left
//        self.navigationController?.pushViewController(controller, animated: true)
    }
    
    @IBAction func rightFlagPressed(_ sender: UIButton) {
        let storyboard = UIStoryboard(name: "Main", bundle: nil)
        guard let controller = storyboard.instantiateViewController(withIdentifier: Constants.ListStoryboardID) as? CurrencyListViewController else { return }
        controller.delegate = self
        controller.buttonType = .right
        self.navigationController?.pushViewController(controller, animated: true)
    }
    
    @IBAction func hideKeyboardTapGesture(_ sender: UITapGestureRecognizer) {
        view.endEditing(true)
    }
}

//MARK: - Extensions

extension ConverterViewController: CurrencyManagerDelegate {
    func didFailWithError(error: String) {
        let alert = UIAlertController(title: error, message: nil, preferredStyle: .alert)
        
        alert.addAction(UIAlertAction(title: "OK", style: .default, handler: { action in
            print("You choose OK")
        }))
        self.present(alert, animated: true)
    }
}

extension ConverterViewController: ButtonHandler {
    func didSelect(key: String, button: ButtonType) {
        switch button {
        case .left:
            if let leftImage = UIImage(named: key) {
                leftFlagImage.image = leftImage
            } else {
                leftFlagImage.image = UIImage(named: "no_image")
            }
            leftCurrencyLabel.text = key
        case .right:
            if let rightImage = UIImage(named: key) {
                rightFlagImage.image = rightImage
            } else {
                rightFlagImage.image = UIImage(named: "no_image")
            }
            rightCurrencyLabel.text = key
        }
    }
}

extension ConverterViewController: UITextFieldDelegate {
    func textField(_ textField: UITextField, shouldChangeCharactersIn range: NSRange, replacementString string: String) -> Bool {
        switch textField.tag {
        case 1:
            rightTextField.text = String(converter(left: Double(textField.text ?? "") ?? 0, right: 1, tag: 1))
        case 2:
            return false
        default:
            break
        }
        return true
    }
}

