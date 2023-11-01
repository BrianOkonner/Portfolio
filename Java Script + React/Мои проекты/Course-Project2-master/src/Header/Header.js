import './Header.css'
import logo from "../assets/logo.png"

const Header = () => {
    const c={'background-color':"#40bf21"};
  return (
    <div className="Header-header" style={c}>
    <h1>Расписание транспорта<img className="Header-logo" src={logo} alt="
    Train"/></h1>
    <h2>Минск</h2>     
    </div>
  );
};
export default Header;