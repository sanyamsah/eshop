import { Link } from "react-router-dom";

const Category = (props) => {
    const { id, name, image } = props.data;
    return (
        <div className="col-sm-3 mb-4"> {/* Added margin-bottom for spacing */}
            <div className="card">
                <img src={image} alt={name} className="card-img-top" /> {/* Fixed className */}
                <div className="card-body">
                    <h5 className="card-title">{name}</h5>
                    <p className="card-text">
                        With supporting text below as a natural lead-in to additional content.
                    </p>
                    <Link to="/products" className="btn btn-primary btn-block">Click Here</Link>
                </div>
            </div>
        </div>
    );
}
export default Category;