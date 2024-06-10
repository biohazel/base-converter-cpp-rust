use std::io::{self, Write};

fn to_decimal(num: &str, base: u128) -> u128 {
    let mut result: u128 = 0;
    for c in num.chars() {
        result = result * base;
        if c >= '0' && c <= '9' {
            result += c as u128 - '0' as u128;
        } else if c >= 'A' && c <= 'F' {
            result += 10 + c as u128 - 'A' as u128;
        } else if c >= 'a' && c <= 'f' {
            result += 10 + c as u128 - 'a' as u128;
        }
    }
    result
}

fn from_decimal(mut num: u128, base: u128) -> String {
    const DIGITS: &str = "0123456789ABCDEF";
    if num == 0 {
        return "0".to_string();
    }
    let mut result = String::new();
    while num > 0 {
        let rem = (num % base) as usize;
        result.insert(0, DIGITS.chars().nth(rem).unwrap());
        num /= base;
    }
    result
}

fn main() {
    let mut num = String::new();
    let mut base_antes = String::new();
    let mut base_depois = String::new();
    
    print!("Digite o número que será convertido, e em que base ele está. Opções de base: [D]ecimal, [H]exadecimal ou [B]inária.\n");
    io::stdout().flush().unwrap();
    io::stdin().read_line(&mut num).unwrap();
    num = num.trim().to_string();
    
    io::stdin().read_line(&mut base_antes).unwrap();
    base_antes = base_antes.trim().to_string();
    
    print!("Agora digite para qual base deseja converter.\n");
    io::stdout().flush().unwrap();
    io::stdin().read_line(&mut base_depois).unwrap();
    base_depois = base_depois.trim().to_string();

    let base1 = if base_antes == "D" { 10 } else if base_antes == "H" { 16 } else { 2 };
    let base2 = if base_depois == "D" { 10 } else if base_depois == "H" { 16 } else { 2 };

    let num_dec = to_decimal(&num, base1);

    if base2 == 10 {
        println!("O resultado da conversão é: {}", num_dec);
    } else {
        let resultado = from_decimal(num_dec, base2);
        println!("O resultado da conversão é: {}", resultado);
    }
}
